//
// Created by zkw on 2021-04-21.
//

#ifndef PYVM_FUNCTIONOBJECT_HPP
#define PYVM_FUNCTIONOBJECT_HPP

#include <object/Klass.hpp>
#include <object/Object.hpp>
#include <code/CodeObject.hpp>
#include <utils/Map.hpp>

class FunctionKlass : public Klass{
private:
    FunctionKlass();
    static FunctionKlass* instance;

public:
    static FunctionKlass *getInstance();

    void print(Object *obj) override;
};

class NativeFunctionKlass : public Klass{
private:
    NativeFunctionKlass();
    static NativeFunctionKlass *instance;

public:
    static NativeFunctionKlass *getInstance();
};

class FunctionObject : public Object{
friend class FunctionKlass;
friend class FrameObject;

private:
    CodeObject *_funcCode{};
    String     *_funcName{};
    ObjList    _defaults {};
    unsigned int _flags{};
    Map<Object *, Object *> *_globals {};

public:
    explicit FunctionObject(Object *codeObject);
    explicit FunctionObject(Klass *klass);
    FunctionObject();

    String       *funcName()   { return _funcName; }
    unsigned int flags() const { return _flags;    }
    Map<Object *, Object *> *globals() { return _globals; }
    void setGlobals(Map<Object *, Object *> *globals){
        _globals = globals;
    }
    void setDefault(ObjList defaults);
    ObjList defaults() { return _defaults; }
};


#endif //PYVM_FUNCTIONOBJECT_HPP
