//
// Created by zkw on 2021-04-12.
//

#ifndef CPP_INTERPRETER_HPP
#define CPP_INTERPRETER_HPP
#include "../code/CodeObject.hpp"
#include "FrameObject.hpp"

class Block;
class Interpreter {
public:
    Interpreter();
    void evalFrame();
    void leaveFrame();
    void destroyFrame();
    void run(CodeObject *codes);
    void buildFrame(Object *callable, ObjList args);

private:
    FrameObject *_frame{};
    Object      *_retValue{};
    Map<Object *, Object *> *_builtins;
};

class Block{
public:
    int           _level;
    unsigned char _type;
    unsigned int  _target;

    explicit Block(unsigned char bType = 0, unsigned int bTarget = 0, int bLevel = 0):
        _type(bType),
        _target(bTarget),
        _level(bLevel){}

    Block(const Block& b) {
        _type = b._type;
        _level  = b._level;
        _target = b._target;
    }
};


#endif //CPP_INTERPRETER_HPP
