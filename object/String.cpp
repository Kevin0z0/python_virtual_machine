//
// Created by zkw on 2021-04-10.
//

#include "String.hpp"
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
