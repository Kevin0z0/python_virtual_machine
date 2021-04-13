//
// Created by zkw on 2021-04-10.
//

#include "Object.hpp"
#include "cstdio"
#include "../runtime/Universe.hpp"

Object *Object::add(Object *x) {
    return nullptr;
}

void Object::print() {
    printf("None");
}

Object *Object::ge(Object *x) {
    return Universe::False;
}

Object *Object::le(Object *x) {
    return Universe::False;
}

Object *Object::not_equal(Object *x) {
    if(x != this)
        return Universe::True;
    return Universe::False;
}

Object *Object::equal(Object *x) {
    if(x == this)
        return Universe::True;
    return Universe::False;
}

Object *Object::less(Object *x) {
    return Universe::False;
}

Object *Object::greater(Object *x) {
    return Universe::False;
}
