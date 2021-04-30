//
// Created by zkw on 2021-04-16.
//

#ifndef PYVM_KLASS_HPP
#define PYVM_KLASS_HPP
#include "cstdio"

class Object;
class String;
class List;

class Klass {
private:
    String  *_name;
    Klass   *_super;
public:
    Klass();

    void    setSuper(Klass *x)  {_super = x;   }
    void    setName(String *x)  {_name = x;    }

    Klass  *super()             {return _super;}
    String *name()              {return _name; }

    virtual Object *greater   (Object *x, Object *y) { return nullptr; }
    virtual Object *less      (Object *x, Object *y) { return nullptr; }
    virtual Object *equal     (Object *x, Object *y) { return nullptr; }
    virtual Object *not_equal (Object *x, Object *y) { return nullptr; }
    virtual Object *ge        (Object *x, Object *y) { return nullptr; }
    virtual Object *le        (Object *x, Object *y) { return nullptr; }
    virtual Object *add       (Object *x, Object *y) { return nullptr; }
    virtual Object *sub       (Object *x, Object *y) { return nullptr; }
    virtual Object *mul       (Object *x, Object *y) { return nullptr; }
    virtual Object *div       (Object *x, Object *y) { return nullptr; }
    virtual Object *mod       (Object *x, Object *y) { return nullptr; }
    virtual Object *subscr    (Object *x, Object *y) { return nullptr; }
    virtual Object *contains  (Object *x, Object *y) { return nullptr; }
    virtual Object *len       (Object *x)            { return nullptr; }
    virtual void    print     (Object *obj)   { printf("None"); }
};


#endif //PYVM_KLASS_HPP
