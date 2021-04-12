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
    void print() override;

    Object *add(Object *x) override;
    Object *greater(Object *x) override;
    Object *less(Object *x) override;
    Object *equal(Object *x) override;
    Object *ge(Object *x) override;
    Object *le(Object *x) override;

    friend std::ostream &operator<<(std::ostream &os, Integer &i){
        std::cout << i._value;
        return os;
    }
};


#endif //CPP_INTEGER_HPP
