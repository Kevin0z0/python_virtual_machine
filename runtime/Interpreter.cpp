//
// Created by zkw on 2021-04-12.
//
#include "iostream"
#include "Interpreter.hpp"
#include "../code/ByteCode.hpp"
#include "../object/Integer.hpp"
#include "../runtime/Universe.hpp"

#define PUSH(x) _frame->stack()->add((x))
#define POP() _frame->stack()->pop()
#define STACK_LEVEL() _frame->stack()->size()

void Interpreter::run(CodeObject *codes) {
    _frame = new FrameObject(codes);
    evalFrame();
    destroyFrame();
}

void Interpreter::buildFrame(Object *callable) {
    auto *frame = new FrameObject((FunctionObject *)callable);
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
    _map = Map<Object *, Object *>(_frame->names()->size());

    while(_frame->hasMoreCodes()){
        unsigned char opCode = _frame->getOpCode();
        bool hasArgument = (opCode & 0xff) >= ByteCode::HAVE_ARGUMENT;
        int opArg = -1;
        if(hasArgument) opArg = _frame->getOpArg();

        Integer *lhs, *rhs;
        Object *v, *w, *u, *attr;
        Block *b;
        FunctionObject *fo;
        switch (opCode) {
            case ByteCode::POP_TOP:
                POP();
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
                    default:
                        printf("Error: Unrecognized compare op %d\n", opArg);
                }
                break;
            case ByteCode::POP_JUMP_IF_FALSE:
                v = POP();
                if(v == Universe::False)
                    _frame->setPC(opArg);
                break;
            case ByteCode::STORE_NAME:
                _map.set(_frame->names()->get(opArg), POP());
                break;
            case ByteCode::LOAD_NAME:
                PUSH(_map.get(_frame->names()->get(opArg)));
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
                PUSH(fo);
                break;
            case ByteCode::CALL_FUNCTION:
                buildFrame(POP());
                break;
            default:
                printf("Error: Unrecognized byte code %d\n", opCode);
        }
    }
}
