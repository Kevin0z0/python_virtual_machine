//
// Created by zkw on 2021-04-10.
//

#include <runtime/Universe.hpp>
#include "runtime/FunctionObject.hpp"
#include "Object.hpp"
ObjectKlass *ObjectKlass::instance = nullptr;

ObjectKlass::ObjectKlass() = default;

ObjectKlass *ObjectKlass::get_instance() {
    if(instance == nullptr)
        instance = new ObjectKlass();
    return instance;
}

Object::Object() {
    _klass = new Klass();
}

Object *Object::add(Object *x) {
    return klass()->add(this, x);
}

void Object::print() {
    klass()->print(this);
}

Object *Object::ge(Object *x) {
    return klass()->ge(this, x);
}

Object *Object::le(Object *x) {
    return klass()->le(this, x);
}

Object *Object::not_equal(Object *x) {
    return klass()->not_equal(this, x);
}

Object *Object::equal(Object *x) {
    return klass()->equal(this, x);
}

Object *Object::less(Object *x) {
    return klass()->less(this, x);
}

Object *Object::greater(Object *x) {
    return klass()->greater(this, x);
}

Object *Object::sub(Object *x) {
    return klass()->sub(this, x);
}

Object *Object::mul(Object *x) {
    return klass()->mul(this, x);
}

Object *Object::div(Object *x) {
    return klass()->div(this, x);
}

Object *Object::mod(Object *x) {
    return klass()->mod(this, x);
}

Object *Object::subscr(Object *x) {
    return klass()->subscr(this, x);
}

Object *Object::contains(Object *x) {
    return klass()->contains(this, x);
}

Object *Object::len() {
    return klass()->len(this);
}

Object *Object::getAttr(Object *x) {
    Object *result = Universe::None;
    result = klass()->klassDict()->get(x);

    if(result == Universe::None)
        return result;
    if(MethodObject::isFunction(result)){
        result = new MethodObject((FunctionObject *)result, this);
    }
    return result;
}



