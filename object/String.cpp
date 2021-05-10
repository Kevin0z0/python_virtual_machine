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

String::String(const char *x, const unsigned int length): _length(length) {
    _value = new char[_length];
    for(unsigned int i = 0; i < length; i++){
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

long int* getNext(String *p){
    auto length = (long int)p->length();
    auto *next = new long int[length];
    long int l = 0;
    long int r = 1;
    next[0] = 0;
    const char *val = p->value();
    while(r < length){
        if(val[l] == val[r]){
            next[r] = next[r - 1] + 1;
            l++;
            r++;
        }else{
            l = 0;
            if(val[l] == val[r]){
                next[r] = 1;
                l++;
            }
            else
                next[r] = 0;
            r++;
        }
    }
    return next;
}

long int KMP(String *s, String *p){
    long int l = 0;
    long int r = 0;
    long int len = 0;
    auto lenS = (long int)s->length();
    auto lenP = (long int)p->length();
    long int *next = getNext(p);
    if(lenP > lenS) return -1;
    const char *val1 = s->value();
    const char *val2 = p->value();
    while(r < lenP && l < lenS ){
        if(val1[l] == val2[r]){
            LOOP:
            l++;
            r++;
            len++;
        }else{
            r = next[len ? r - 1 : len];
            if(val1[l] == val2[r]){
                len = r;
                goto LOOP;
            }
            len = r = 0;
            l++;
        }
        if(len == lenP)
            return l - lenP;
    }
    return -1;
}

Object *StringKlass::contains(Object *x, Object *y) {
    assert(x && x->klass() == (Klass *)this);
    assert(y && y->klass() == (Klass *)this);

    auto *sx = (String *)x;
    auto *sy = (String *)y;

    if(KMP(sx, sy) > -1)
        return Universe::True;
    return Universe::False;
}

Object *StringKlass::len(Object *x) {
    return new Integer(((String *)x)->length());
}