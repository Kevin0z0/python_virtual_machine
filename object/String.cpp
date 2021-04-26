//
// Created by zkw on 2021-04-10.
//

#include "String.hpp"
#include "runtime/Universe.hpp"
#include <cstring>
StringKlass *StringKlass::instance = nullptr;
StringKlass::StringKlass() = default;

StringKlass *StringKlass::getInstance() {
    if(instance == nullptr)
        instance = new StringKlass();
    return instance;
}

String::String(const char *x, const int length): _length(length) {
    _value = new char[_length];
    for(int i = 0; i < length; i++){
        _value[i] = x[i];
    }
    setKlass(StringKlass::getInstance());
}

String::String(const char *x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
    setKlass(StringKlass::getInstance());
}

Object *StringKlass::equal(Object* x, Object *y) {
    if(x->klass() != y->klass())
        return Universe::False;

    auto *sx = (String *)x;
    auto *sy = (String *)y;

    assert(sx && sx->klass() == (Klass *)this);
    assert(sy && sy->klass() == (Klass *)this);

    if(sx->length() != sy->length())
        return Universe::False;
    for(int i = 0; i < sx->length(); i++){
        if(sx->value()[i] != sy->value()[i])
            return Universe::False;
    }
    return Universe::True;
}

void StringKlass::print(Object *x) {
    auto *str = (String *)x;
    assert(str && str->klass() == (Klass *)this);

    for(int i = 0; i <str->length(); i++){
        printf("%c", str->value()[i]);
    }
}

Object *StringKlass::subscr(Object *x, Object *y) {
    assert(x && x->klass() == (Klass *)this);
    assert(y && y->klass() == (Klass *)IntegerKlass::getInstance());

    auto *sx = (String *)x;
    auto *sy = (Integer *)y;
    return new String(&(sx->value()[sy->value()]), 1);
}

Object *StringKlass::contains(Object *x, Object *y) {
    assert(x && x->klass() == (Klass *)this);
    assert(y && y->klass() == (Klass *)this);

    auto *sx = (String *)x;
    auto *sy = (String *)y;



}
