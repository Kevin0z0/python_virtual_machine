//
// Created by zkw on 2021-04-10.
//

#ifndef CPP_OBJECT_HPP
#define CPP_OBJECT_HPP

#include "Klass.hpp"
#include "cassert"
class String;

class ObjectKlass : public Klass{
private:
    ObjectKlass();
    static ObjectKlass* instance;

public:
    static ObjectKlass* get_instance();
};

class Object {
private:
    Klass *_klass;
public:
    Object();

    Klass *klass(){
        assert(_klass != nullptr);
        return _klass;
    }
    void setKlass(Klass *x){
        _klass = x;
    }
    void print();

    Object *add       (Object *x);
    Object *sub       (Object *x);
    Object *mul       (Object *x);
    Object *div       (Object *x);
    Object *mod       (Object *x);
    Object *greater   (Object *x);
    Object *less      (Object *x);
    Object *equal     (Object *x);
    Object *not_equal (Object *x);
    Object *ge        (Object *x);
    Object *le        (Object *x);

};


#endif //CPP_OBJECT_HPP
