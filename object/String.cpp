//
// Created by zkw on 2021-04-10.
//

#include "String.hpp"
#include "../runtime/Universe.hpp"
#include <cstring>

String::String(const char *x, const int length): _length(length) {
    _value = new char[_length];
    for(int i = 0; i < length; i++){
        _value[i] = x[i];
    }
}

String::String(const char *x) {
    _length = strlen(x);
    _value = new char[_length];
    strcpy(_value, x);
}

void String::print() {
    for(int i = 0; i < _length; i++){
        std::cout << _value[i];
    }
//    std::cout << std::endl;
}

Object *String::equal(Object* x) {
    if(_value == ((String*)x)->_value)
        return Universe::True;
    return Universe::False;
}
