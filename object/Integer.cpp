//
// Created by zkw on 2021-04-10.
//

#include "Integer.hpp"
#include "../runtime/Universe.hpp"

IntegerKlass *IntegerKlass::instance = nullptr;
IntegerKlass::IntegerKlass() = default;

IntegerKlass *IntegerKlass::getInstance() {
    if(instance == nullptr)
        instance = new IntegerKlass();
    return instance;
}

Integer::Integer(int x) : _value(x) {
    setKlass(IntegerKlass::getInstance());
}

Object *IntegerKlass::add(Object *x, Object *y) {
    auto *ix = (Integer*) x;
    auto *iy = (Integer*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new Integer(ix->value() + iy->value());
}

Object *IntegerKlass::greater(Object *x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *ix = (Integer *)x;
    auto *iy = (Integer *)y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    if(ix->value() > iy->value())
        return Universe::True;
    return Universe::False;
}

Object *IntegerKlass::less(Object *x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *ix = (Integer *)x;
    auto *iy = (Integer *)y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    if(ix->value() < iy->value())
        return Universe::True;
    return Universe::False;
}

Object *IntegerKlass::equal(Object *x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *ix = (Integer *)x;
    auto *iy = (Integer *)y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    if(ix->value() == iy->value())
        return Universe::True;
    return Universe::False;
}

Object *IntegerKlass::not_equal(Object *x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *ix = (Integer *)x;
    auto *iy = (Integer *)y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    if(ix->value() != iy->value())
        return Universe::True;
    return Universe::False;
}

Object *IntegerKlass::ge(Object *x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *ix = (Integer *)x;
    auto *iy = (Integer *)y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    if(ix->value() >= iy->value())
        return Universe::True;
    return Universe::False;
}

Object *IntegerKlass::le(Object *x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *ix = (Integer *)x;
    auto *iy = (Integer *)y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    if(ix->value() <= iy->value())
        return Universe::True;
    return Universe::False;
}

Object *IntegerKlass::sub(Object *x, Object *y) {
    auto *ix = (Integer*) x;
    auto *iy = (Integer*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new Integer(ix->value() - iy->value());
}

Object *IntegerKlass::mul(Object *x, Object *y) {
    auto *ix = (Integer*) x;
    auto *iy = (Integer*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new Integer(ix->value() * iy->value());
}

Object *IntegerKlass::div(Object *x, Object *y) {
    auto *ix = (Integer*) x;
    auto *iy = (Integer*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new Integer(ix->value() / iy->value());
}

Object *IntegerKlass::mod(Object *x, Object *y) {
    auto *ix = (Integer*) x;
    auto *iy = (Integer*) y;

    assert(ix && (ix->klass() == (Klass *)this));
    assert(iy && (iy->klass() == (Klass *)this));

    return new Integer(ix->value() % iy->value());
}

void IntegerKlass::print(Object *x) {
    printf("%d", ((Integer *)x)->value());
}





