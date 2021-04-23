//
// Created by zkw on 2021-04-21.
//

#ifndef PYVM_FUNCTIONOBJECT_HPP
#define PYVM_FUNCTIONOBJECT_HPP

#include <object/Klass.hpp>
#include <object/Object.hpp>
#include <code/CodeObject.hpp>

class FunctionKlass : public Klass{
private:
    FunctionKlass();
    static FunctionKlass* instance;

public:
    static FunctionKlass *getInstance();

    void print(Object *obj) override;
};

class FunctionObject : public Object{
friend class FunctionKlass;
friend class FrameObject;

private:
    CodeObject *_funcCode{};
    String     *_funcName{};
    unsigned int _flags{};

public:
    explicit FunctionObject(Object *codeObject);
    explicit FunctionObject(Klass *klass);
    FunctionObject();

    String       *funcName()   { return _funcName; }
    unsigned int flags() const { return _flags;    }
};


#endif //PYVM_FUNCTIONOBJECT_HPP
