//
// Created by zkw on 2021-04-12.
//

#ifndef CPP_UNIVERSE_HPP
#define CPP_UNIVERSE_HPP
#include "../object/Integer.hpp"

class Universe {
public:
    static Integer *True;
    static Integer *False;

    static Object *None;
public:
    static void genesis();
    static void destory();
};

#endif //CPP_UNIVERSE_HPP
