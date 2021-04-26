//
// Created by zkw on 2021-04-10.
//
#ifndef CPP_STRING_HPP
#define CPP_STRING_HPP
#include "Object.hpp"

class StringKlass : public Klass {
private:
    StringKlass();
    static StringKlass *instance;

public:
    static StringKlass *getInstance();
    void   print      (Object *x) override;
    Object *equal     (Object *x, Object *y) override;
    Object *subscr    (Object *x, Object *y) override;
    Object *contains  (Object *x, Object *y) override;
};

class String : public Object {
private:
    char *_value;
    unsigned int _length;

public:
    explicit String(const char *x);
    explicit String(const char *x, int length);

    const char *value() {return _value;}
    unsigned int length() const {return _length;}
};

#endif //CPP_STRING_HPP
