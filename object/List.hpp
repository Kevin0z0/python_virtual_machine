//
// Created by zkw on 2021-04-26.
//

#ifndef PYVM_LIST_HPP
#define PYVM_LIST_HPP

#include "Klass.hpp"
#include "Object.hpp"
#include "utils/ArrayList.hpp"

class ListKlass : public Klass{
private:
    ListKlass();
    static ListKlass *instance;
public:
    static ListKlass *getInstance();
    void print(Object *obj) override;
    Object *subscr (Object *x, Object *y) override;
    Object *contains (Object *x, Object *y) override;
};


class List : public Object{
    friend class ListKlass;

private:
    ObjList _innerList;

public:
    List();
    explicit List(ObjList obj);
    ArrayList<Object *> *innerList()    { return _innerList;            }
    int size     ()                     { return _innerList->size();    }
    Object *top  ()                     { return get(size() - 1); }
    Object *pop  ()                     { return _innerList->pop();     }
    Object *get  (int index)            { return _innerList->get(index);}
    void append  (Object* obj)          { _innerList->add(obj);         }
    void set     (int i, Object *obj)   { _innerList->set(i, obj);      }

};


#endif //PYVM_LIST_HPP
