//
// Created by zkw on 2021-04-21.
//

#include "FunctionObject.hpp"
#include "Universe.hpp"

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
NativeFunctionKlass::NativeFunctionKlass(){
    setSuper(FunctionKlass::getInstance());
};

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

FunctionObject::FunctionObject(NativeFuncPointer nfp) {
    _funcCode   = nullptr;
    _funcName   = nullptr;
    _flags      = 0;
    _globals    = nullptr;
    _nativeFunc = nfp;

    setKlass(NativeFunctionKlass::getInstance());
}

Object *FunctionObject::call(ObjList args) {
    return (*_nativeFunc)(args);
}


/**
 * MethodKlass
 */

MethodKlass *MethodKlass::instance = nullptr;
MethodKlass *MethodKlass::getInstance() {
    if(instance == nullptr)
        instance = new MethodKlass();
    return instance;
}
MethodKlass::MethodKlass() {
    setKlassDict(new Dict());
}

bool MethodObject::isFunction(Object *x) {
    Klass* k = x->klass();
    if (k == (Klass *) FunctionKlass::getInstance())
        return true;

    while (k->super() != nullptr) {
        k = k->super();
        if (k == (Klass*) FunctionKlass::getInstance())
            return true;
    }
    return false;
}

/**
 * Native Functions
 */
Object* len(ObjList args){
    return args->get(0)->len();
}

Object* stringUpper(ObjList args){
    Object *arg0 = args->get(0);
    assert(arg0->klass() == StringKlass::getInstance());

    auto strObj = (String *)arg0;
    auto length = strObj->length();
    if(length == 0) return Universe::None;

    char *v = new char[length];
    char c;

    for(unsigned int i = 0; i < length; i++ ){
        c = strObj->value()[i];
        if(c > 'a' && c <='z')
            v[i] = c - 0x20;
        else
            v[i] = c;
    }

    auto *s = new String(v, length);
    delete [] v;
    return s;
}

