//
// Created by zkw on 2021-04-10.
//

#ifndef CPP_OBJECT_HPP
#define CPP_OBJECT_HPP


class Object {
public:
    virtual void print();

    virtual Object *add       (Object *x);
    virtual Object *greater   (Object *x);
    virtual Object *less      (Object *x);
    virtual Object *equal     (Object *x);
    virtual Object *not_equal (Object *x);
    virtual Object *ge        (Object *x);
    virtual Object *le        (Object *x);
};


#endif //CPP_OBJECT_HPP
