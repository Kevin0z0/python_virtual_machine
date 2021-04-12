//
// Created by zkw on 2021-04-12.
//

#ifndef CPP_INTERPRETER_HPP
#define CPP_INTERPRETER_HPP


#include "../code/CodeObject.hpp"

class Interpreter {
public:
    void run(CodeObject *codes);

private:
    ArrayList<Object*> *_stack;
    ArrayList<Object*> *_consts;
};


#endif //CPP_INTERPRETER_HPP
