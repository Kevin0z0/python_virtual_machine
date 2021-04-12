//
// Created by zkw on 2021-04-10.
//
#ifndef u_int
#define u_int unsigned int
#endif

#ifndef CPP_STRING_HPP
#define CPP_STRING_HPP
#include "Object.hpp"
#include <iostream>

class String : public Object {
private:
    char *_value;
    u_int _length;

public:
    explicit String(const char *x);
    explicit String(const char *x, int length);

    const char *value() {return _value;}
    u_int length() const {return _length;}

    friend std::ostream& operator<<(std::ostream &os, String &s){
        for(int i = 0; i < s._length; i++){
            std::cout << s._value[i];
        }
        return os;
    }

};


#endif //CPP_STRING_HPP
