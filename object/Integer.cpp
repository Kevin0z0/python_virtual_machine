//
// Created by zkw on 2021-04-10.
//

#include "Integer.hpp"
#include "../runtime/Universe.hpp"

Integer::Integer(int x) : _value(x) {}

Object *Integer::add(Object *x) {
    return new Integer(_value + ((Integer*)x)->value());
}

void Integer::print() {
    printf("%d",_value);
}

Object *Integer::greater(Object *x) {
    if(_value > ((Integer*)x)->_value)
        return Universe::True;
    return Universe::False;
}

Object *Integer::less(Object *x) {
    if(_value < ((Integer*)x)->_value)
        return Universe::True;
    return Universe::False;
}

Object *Integer::equal(Object *x) {
    if(_value == ((Integer*)x)->_value)
        return Universe::True;
    return Universe::False;
}

Object *Integer::not_equal(Object *x) {
    if(_value != ((Integer*)x)->_value)
        return Universe::True;
    return Universe::False;
}

Object *Integer::ge(Object *x) {
    if(_value >= ((Integer*)x)->_value)
        return Universe::True;
    return Universe::False;
}

Object *Integer::le(Object *x) {
    if(_value <= ((Integer*)x)->_value)
        return Universe::True;
    return Universe::False;
}


