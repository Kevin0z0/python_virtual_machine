//
// Created by zkw on 2021-04-12.
//

#include "Interpreter.hpp"
#include "../code/ByteCode.hpp"
#include "../object/Integer.hpp"
#include "../runtime/Universe.hpp"
#include "../utils/Map.hpp"

#define PUSH(x) _stack->add((x))
#define POP() _stack->pop()

void Interpreter::run(CodeObject *codes) {
    int pc = 0;
    unsigned int codeLength = codes->_bytecodes->length();

    _stack = new ArrayList<Object*>(codes->_stackSize);
    _consts = codes->_consts;
    _names = codes->_names;

    Map<Object*, Object*> map(_names->size());

    while(pc < codeLength){
        unsigned char opCode = codes->_bytecodes->value()[pc++];
        bool hasArgument = (opCode & 0xff) >= ByteCode::HAVE_ARGUMENT;
        int opArg = -1;
        if(hasArgument){
            int byte1 = (codes->_bytecodes->value()[pc++] & 0xff);
            opArg = ((codes->_bytecodes->value()[pc++] & 0xff) << 8) | byte1;
        }
        Integer *lhs, *rhs;
        Object *v, *w, *u, *attr;
        switch (opCode) {
            case ByteCode::LOAD_CONST:
                PUSH(_consts->get(opArg));
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
                POP();
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
                    pc = opArg;
                break;
            case ByteCode::STORE_NAME:
                map.set(_names->get(opArg), POP());
                break;
            case ByteCode::LOAD_NAME:
                PUSH(map.get(_names->get(opArg)));
                break;
            case ByteCode::JUMP_FORWARD:
                pc += opArg;
                break;
            case ByteCode::JUMP_ABSOLUTE:
                pc = opArg;
                break;
            case ByteCode::SETUP_LOOP:
                break;
            case ByteCode::POP_BLOCK:
                break;
            default:
                printf("Error: Unrecognized byte code %x\n", opCode);
        }
    }
}
