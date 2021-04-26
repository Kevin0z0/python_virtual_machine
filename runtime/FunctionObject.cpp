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

/**
 * NativeFunctionKlass
 */
NativeFunctionKlass *NativeFunctionKlass::instance = nullptr;
NativeFunctionKlass::NativeFunctionKlass() = default;

NativeFunctionKlass *NativeFunctionKlass::getInstance() {
    if(instance == nullptr)
        instance = new NativeFunctionKlass();
    return instance;
}

/**
 * FunctionObject
 */
FunctionObject::FunctionObject() = default;
FunctionObject::FunctionObject(Object *codeObject) {
    auto *co = (CodeObject *) codeObject;
    _funcCode = co;
    _funcName = co->_coName;
    _flags    = co->_flag;
    _defaults   = nullptr;

    setKlass(FunctionKlass::getInstance());
}

FunctionObject::FunctionObject(Klass *klass) {
    _funcCode = nullptr;
    _funcName = nullptr;
    _flags    = 0;
    _defaults   = nullptr;
    setKlass(klass);
}

void FunctionObject::setDefault(ObjList defaults) {
    if(defaults == nullptr) return;

    _defaults = new ArrayList<Object *>(defaults->size());
    for(int i = 0; i < defaults->size(); i++){
        _defaults->set(i, defaults->get(i));
    }

}

