//
// Created by zkw on 2021-04-12.
//

#include "Universe.hpp"

Integer *Universe::True  = nullptr;
Integer *Universe::False = nullptr;
Object *Universe::None  = nullptr;

void Universe::genesis() {
    True  = new Integer(1);
    False = new Integer(0);
    None  = new Object();
}

void Universe::destory() {

}
