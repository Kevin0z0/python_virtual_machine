//
// Created by zkw on 2021-04-10.
//

#include "utils/Print.hpp"

CodeObject::CodeObject(int argCount,
                       int nlocals,
                       int stackSize,
                       int flag,
                       String *bytecodes,
                       ArrayList<Object *> *consts,
                       ArrayList<Object *> *names,
                       ArrayList<Object *> *varNames,
                       ArrayList<Object *> *freevars,
                       ArrayList<Object *> *cellvars,
                       String *filename,
                       String *coName,
                       int lineNo,
                       String *notable) :
                       _argCount(argCount),
                       _nLocals(nlocals),
                       _stackSize(stackSize),
                       _flag(flag),
                       _bytecodes(bytecodes),
                       _consts(consts),
                       _names(names),
                       _varNames(varNames),
                       _freevars(freevars),
                       _cellvars(cellvars),
                       _filename(filename),
                       _coName(coName),
                       _lineNo(lineNo),
                       _notable(notable) {}

void CodeObject::print() {
    printf("\n");
    Print(this);
}

