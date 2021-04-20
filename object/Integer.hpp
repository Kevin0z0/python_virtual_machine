//
// Created by zkw on 2021-04-10.
//

#ifndef CPP_INTEGER_HPP
#define CPP_INTEGER_HPP
#include "Object.hpp"
#include <iostream>

class Integer : public Object{
private:
    int _value;
public:
    explicit Integer(int x);
    int value() const {return _value;}

    friend std::ostream &operator<<(std::ostream &os, Integer &i){
        std::cout << i._value;
        return os;
    }
};

class IntegerKlass : public Klass{
private:
    IntegerKlass();
    static IntegerKlass *instance;

public:
    static IntegerKlass *getInstance();

    virtual void print(Object *x);
    
    virtual Object *add(Object *x, Object *y);
    virtual Object *sub(Object *x, Object *y);
    virtual Object *mul(Object *x, Object *y);
    virtual Object *div(Object *x, Object *y);
    virtual Object *mod(Object *x, Object *y);

    virtual Object *greater(Object *x, Object *y);
    virtual Object *less(Object *x, Object *y);
    virtual Object *equal(Object *x, Object *y);
    virtual Object *not_equal(Object *x, Object *y);
    virtual Object *ge(Object *x, Object *y);
    virtual Object *le(Object *x, Object *y);
};

#endif //CPP_INTEGER_HPP
