//
// Created by zkw on 2021-04-12.
//
#include <object/List.hpp>
#include "iostream"
#include "Interpreter.hpp"
#include "code/ByteCode.hpp"
#include "object/Integer.hpp"
#include "runtime/Universe.hpp"

#define PUSH(x) _frame->stack()->add((x))
#define POP() _frame->stack()->pop()
#define STACK_LEVEL() _frame->stack()->size()

#define True Universe::True
#define False Universe::False
#define None Universe::None


Interpreter::Interpreter() {
    _builtins = new Map<Object *, Object *>();
    _builtins->set(new String("None"),  None);
    _builtins->set(new String("True"),  True);
    _builtins->set(new String("False"), False);
}

void Interpreter::run(CodeObject *codes) {
    _frame = new FrameObject(codes);
    evalFrame();
    destroyFrame();
}

void Interpreter::buildFrame(Object *callable, ObjList args) {
    auto *frame = new FrameObject((FunctionObject *)callable, args);
    frame->setSender(_frame);
    _frame = frame;
}

void Interpreter::leaveFrame(){
    destroyFrame();
    PUSH(_retValue);
}

void Interpreter::destroyFrame() {
    FrameObject *temp = _frame;
    _frame = _frame->sender();
    delete temp;
}

void Interpreter::evalFrame() {
    while(_frame->hasMoreCodes()){
        unsigned char opCode = _frame->getOpCode();
        bool hasArgument = (opCode & 0xff) >= ByteCode::HAVE_ARGUMENT;
        int opArg = -1;
        if(hasArgument) opArg = _frame->getOpArg();

        Integer *lhs, *rhs;
        Object *v, *w, *u, *attr;
        Block *b;
        FunctionObject *fo;
        ObjList args = nullptr;
        switch (opCode) {
            case ByteCode::POP_TOP:
                u = POP();
                break;
            case ByteCode::LOAD_CONST:
                PUSH(_frame->consts()->get(opArg));
                break;
            case ByteCode::PRINT_ITEM:
                v = POP();
                v->print();
                break;
            case ByteCode::PRINT_NEWLINE:
                printf("\n");
                break;
            case ByteCode::BINARY_ADD:
            case ByteCode::INPLACE_ADD:
                v = POP();
                w = POP();
                PUSH(w->add(v));
                break;
            case ByteCode::RETURN_VALUE:
                _retValue = POP();
                if(_frame->isFirstFrame()) return;

                leaveFrame();
                break;
            case ByteCode::COMPARE_OP:
                w = POP();
                v = POP();

                switch (opArg) {
                    case ByteCode::LESS:
                        PUSH(v->less(w));
                        break;
                    case ByteCode::GREATER:
                        PUSH(v->greater(w));
                        break;
                    case ByteCode::EQUAL:
                        PUSH(v->equal(w));
                        break;
                    case ByteCode::NOT_EQUAL:
                        PUSH(v->not_equal(w));
                        break;
                    case ByteCode::GREATER_EQUAL:
                        PUSH(v->ge(w));
                        break;
                    case ByteCode::LESS_EQUAL:
                        PUSH(v->le(w));
                        break;
                    case ByteCode::IS:
                        PUSH(v == w ? True : False);
                        break;
                    case ByteCode::IS_NOT:
                        PUSH(v == w ? False : True);
                        break;
                    case ByteCode::IN:
                        PUSH(w->contains(v));
                        break;
                    case ByteCode::NOT_IN:
                        u = w->contains(v);
                        if(u == Universe::True){
                            PUSH(Universe::False);
                            break;
                        }
                        PUSH(Universe::True);
                        break;
                    default:
                        printf("Error: Unrecognized compare op %d\n", opArg);
                }
                break;
            case ByteCode::POP_JUMP_IF_FALSE:
                v = POP();
                if(v == False)
                    _frame->setPC(opArg);
                break;
            case ByteCode::STORE_NAME:
                _frame->locals()->set(_frame->names()->get(opArg), POP());
                break;
            case ByteCode::LOAD_NAME:
                v = _frame->names()->get(opArg);
                //先去局部变量表查找变量
                w = _frame->locals()->get(v);
                if(w != None){
                    PUSH(w);
                    break;
                }
                //再去全局变量查找变量
                w = _frame->globals()->get(v);
                if(w != None){
                    PUSH(w);
                    break;
                }
                //最后去builtin变量查找变量
                w = _builtins->get(v);
                if(w != None){
                    PUSH(w);
                    break;
                }

                PUSH(None);
                break;
            case ByteCode::JUMP_FORWARD:
                _frame->setPC(_frame->getPC() + opArg);
                break;
            case ByteCode::JUMP_ABSOLUTE:
                _frame->setPC(opArg);
                break;
            case ByteCode::SETUP_LOOP:
                _frame->loopStack()->add(new Block(
                        opCode,
                        _frame->getPC() + opArg,
                        STACK_LEVEL()
                ));
                break;
            case ByteCode::POP_BLOCK:
                b = _frame->loopStack()->pop();
                while(STACK_LEVEL() > b->_level)
                    POP();
                break;
            case ByteCode::BREAK_LOOP:
                b = _frame->loopStack()->pop();
                while (STACK_LEVEL() > b->_level)
                    POP();
                _frame->setPC(b->_target);
                break;
            case ByteCode::MAKE_FUNCTION:
                v = POP();
                fo = new FunctionObject(v);
                fo->setGlobals(_frame->globals());

                if(opArg > 0){
                    args = new ArrayList<Object *>(opArg);
                    while (opArg--){
                        args->set(opArg, POP());
                    }
                }
                fo->setDefault(args);
                PUSH(fo);
                break;
            case ByteCode::CALL_FUNCTION:
                if(opArg > 0){
                    args = new ArrayList<Object *>;
                    while(opArg--){
                        v = POP();
                        args->set(opArg, v);
                    }
                }
                buildFrame(POP(), args);
                if(args != nullptr){
                    delete args;
                    args = nullptr;
                }
                break;
            case ByteCode::STORE_GLOBAL:
                _frame->globals()->set(_frame->names()->get(opArg),POP());
                break;
            case ByteCode::LOAD_GLOBAL:
                PUSH(_frame->globals()->get(_frame->names()->get(opArg)));
                break;
            case ByteCode::LOAD_FAST:
                PUSH(_frame->fastLocals()->get(opArg));
                break;
            case ByteCode::STORE_FAST:
                _frame->fastLocals()->set(opArg, POP());
                break;
            case ByteCode::BUILD_LIST:
                v = new List;
                while(opArg--)
                    ((List *)v)->set(opArg,POP());
                PUSH(v);
                break;
            case ByteCode::BINARY_SUBSCR:
                v = POP();
                w = POP();
                PUSH(w->subscr(v));
                break;
            default:
                printf("Error: Unrecognized byte code %d\n", opCode);
        }
    }
}


