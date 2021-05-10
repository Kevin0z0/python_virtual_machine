//
// Created by zkw on 2021-04-12.
//

#include <object/String.hpp>
#include "Universe.hpp"
#include "FunctionObject.hpp"

Integer *Universe::True  = nullptr;
Integer *Universe::False = nullptr;
Object *Universe::None   = nullptr;

void Universe::genesis() {
    True  = new Integer(0);
    False = new Integer(0);
    None  = new Object();

    Dict *klassDict = new Dict();
    StringKlass::getInstance()->setKlassDict(klassDict);
    klassDict->set(new String("upper"), new FunctionObject(stringUpper));
}

void Universe::destory() {

}
