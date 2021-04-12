//
// Created by zkw on 2021-04-12.
//

#include "Interpreter.hpp"
#include "../code/ByteCode.hpp"
#include "../object/Integer.hpp"
#include "../runtime/Universe.hpp"

#define PUSH(x) _stack->add((x))
#define POP() _stack->pop()

void Interpreter::run(CodeObject *codes) {
    int pc = 0;
    unsigned int codeLength = codes->_bytecodes->length();

    _stack = new ArrayList<Object*>(codes->_stackSize);
    _consts = codes->_consts;

    while(pc < codeLength){
        unsigned char opCode = codes->_bytecodes->value()[pc++];
        bool hasArgment = (opCode & 0xff) >= ByteCode::HAVE_ARGUMENT;
        int opArg = -1;
        if(hasArgment){
            int byte1 = (codes->_bytecodes->value()[pc++] & 0xff);
            opArg = ((codes->_bytecodes->value()[pc++] & 0xff) << 8) | byte1;
        }
        Integer *lhs, *rhs;
        Object *v, *w, *u, *attr;
        switch (opCode) {
            case ByteCode::LOAD_CONST:
//                printf("LOAD_CONST \n");
                PUSH(_consts->get(opArg));
                break;
            case ByteCode::PRINT_ITEM:
//                printf("PRINT_ITEM \n");
                v = POP();
                v->print();
                break;
            case ByteCode::PRINT_NEWLINE:
//                printf("PRINT_NEWLINE \n");
                printf("\n");
                break;
            case ByteCode::BINARY_ADD:
//                printf("BINARY_ADD \n");
                v = POP();
                w = POP();
                PUSH(w->add(v));
                break;
            case ByteCode::RETURN_VALUE:
//                printf("RETURN_VALUE \n");
                POP();
                break;
            case ByteCode::COMPARE_OP:
//                printf("COMPARE_OP \n");
                w = POP();
                v = POP();

                switch (opArg) {
                    case ByteCode::LESS:
//                        printf("LESS \n");
                        PUSH(v->less(w));
                        break;
                    case ByteCode::GREATER:
//                        printf("GREATER \n");
                        PUSH(v->greater(w));
                        break;
                    case ByteCode::EQUAL:
//                        printf("EQUAL \n");
                        PUSH(v->equal(w));
                        break;
                    case ByteCode::NOT_EQUAL:
//                        printf("NOT_EQUAL \n");
                        PUSH(v->not_equal(w));
                        break;
                    case ByteCode::GREATER_EQUAL:
//                        printf("GREATER_EQUAL \n");
                        PUSH(v->ge(w));
                        break;
                    case ByteCode::LESS_EQUAL:
//                        printf("LESS_EQUAL \n");
                        PUSH(v->le(w));
                        break;
                    default:
                        printf("Error: Unrecognized compare op %d\n", opArg);
                }
                break;
            case ByteCode::POP_JUMP_IF_FALSE:
//                printf("POP_JUMP_IF_FALSE \n");
                v = POP();
                if(v == Universe::False)
                    pc = opArg;
                break;
            case ByteCode::JUMP_FORWARD:
//                printf("JUMP_FORWARD \n");
                pc += opArg;
                break;
            default:
                printf("Error: Unrecognized byte code %x\n", opCode);
        }
    }
}
