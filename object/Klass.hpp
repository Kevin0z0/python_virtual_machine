//
// Created by zkw on 2021-04-16.
//

#ifndef PYVM_KLASS_HPP
#define PYVM_KLASS_HPP
#include "cstdio"

class Object;
class String;

class Klass {
private:
    String *_name;
public:
    Klass();

    void setName(String *x) {_name = x;}
    String *name()          {return _name;}
    virtual void print(Object *obj){ printf("None"); }
    virtual Object *greater(Object *x, Object *y){ return nullptr; }
    virtual Object *less(Object *x, Object *y){ return nullptr; }
    virtual Object *equal(Object *x, Object *y){ return nullptr; }
    virtual Object *not_equal(Object *x, Object *y){ return nullptr; }
    virtual Object *ge(Object *x, Object *y){ return nullptr; }
    virtual Object *le(Object *x, Object *y){ return nullptr; }
    virtual Object *add(Object *x, Object *y){ return nullptr; }
    virtual Object *sub(Object *x, Object *y){ return nullptr; }
    virtual Object *mul(Object *x, Object *y){ return nullptr; }
    virtual Object *div(Object *x, Object *y){ return nullptr; }
    virtual Object *mod(Object *x, Object *y){ return nullptr; }
};


#endif //PYVM_KLASS_HPP
