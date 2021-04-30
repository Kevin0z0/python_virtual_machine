//
// Created by zkw on 2021-04-26.
//

#include <runtime/Universe.hpp>
#include "List.hpp"
#include "Integer.hpp"

ListKlass::ListKlass() = default;
ListKlass *ListKlass::instance = nullptr;

ListKlass *ListKlass::getInstance() {
    if(instance == nullptr)
        instance = new ListKlass;
    return instance;
}

void ListKlass::print(Object *obj) {
    List * lx = (List *)obj;
    assert(lx && lx->klass() == (Klass *)this);

    printf("[");
    int size = lx->_innerList->size();
    if(size >= 1)
        lx->_innerList->get(0)->print();
    for(int i = 1; i < size; i++){
        printf(", ");
        lx->_innerList->get(i)->print();
    }
    printf("]");
}


List::List(){
    setKlass(ListKlass::getInstance());
    _innerList = new ArrayList<Object *>;
};

List::List(ObjList obj) {
    setKlass(ListKlass::getInstance());
    _innerList = obj;
}

Object *ListKlass::subscr(Object *x, Object *y) {
    assert(x && x->klass() == (Klass *)this);
    assert(y && y->klass() == (Klass *)IntegerKlass::getInstance());

    List *lx = (List *)x;
    auto *ly = (Integer *)y;
    return lx->innerList()->get(ly->value());
}

Object *ListKlass::contains(Object *x, Object *y) {
    List *lx = (List *)x;
    assert(x && x->klass() == (Klass *)this);
    int size = lx->_innerList->size();
    for(int i = 0; i < size; i++){
        if(lx->_innerList->get(i)->equal(y))
            return Universe::True;
    }
    return Universe::False;
}

Object *ListKlass::len(Object *x) {
    return new Integer(((List *)x)->size());
}
