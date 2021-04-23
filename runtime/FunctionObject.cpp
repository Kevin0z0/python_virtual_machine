//
// Created by zkw on 2021-04-21.
//

#include "FunctionObject.hpp"

FunctionKlass *FunctionKlass::instance = nullptr;
FunctionKlass::FunctionKlass() = default;

void FunctionKlass::print(Object *obj) {
    printf("<function: ");
    auto *fo = (FunctionObject *)obj;
    assert(fo && fo->klass() == (Klass *)this);
    fo->funcName()->print();
    printf(">");
}

FunctionKlass *FunctionKlass::getInstance() {
    if(instance == nullptr)
        instance = new FunctionKlass();
    return instance;
}

FunctionObject::FunctionObject() = default;
FunctionObject::FunctionObject(Object *codeObject) {
    auto *co = (CodeObject *) codeObject;
    _funcCode = co;
    _funcName = co->_coName;
    _flags    = co->_flag;

    setKlass(FunctionKlass::getInstance());
}

FunctionObject::FunctionObject(Klass *klass) {
    _funcCode = nullptr;
    _funcName = nullptr;
    _flags    = 0;
    setKlass(klass);
}




