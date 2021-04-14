//
// Created by zkw on 2021-04-12.
//

#ifndef CPP_INTERPRETER_HPP
#define CPP_INTERPRETER_HPP


#include "../code/CodeObject.hpp"
class Block;
class Interpreter {
public:
    void run(CodeObject *codes);

private:
    ArrayList<Object*> *_stack;
    ArrayList<Object*> *_consts;
    ArrayList<Object*> *_names;
    ArrayList<Block*>  *_loopStack;
};

class Block{
public:
    unsigned char _type;
    unsigned int _target;
    int _level;

    explicit Block(unsigned char bType = 0, unsigned int bTarget = 0, int bLevel = 0):
        _type(bType),
        _target(bTarget),
        _level(bLevel){}

    Block(const Block& b) {
        _type = b._type;
        _target = b._target;
        _level  = b._level;
    }
};


#endif //CPP_INTERPRETER_HPP
