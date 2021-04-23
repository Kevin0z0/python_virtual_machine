//
// Created by zkw on 2021/4/23.
//

#ifndef PYVM_PRINT_HPP
#define PYVM_PRINT_HPP
#include "iostream"
#include <code/CodeObject.hpp>

class Print {
public:
    explicit Print(CodeObject *mainCode);

private:
    static int indent;
    inline static void printIndent();
    static void print(const std::string &str);
    static void print(const std::string &str, int t);
    static void print(const std::string &str, String *s);
    static void printByte(const std::string &str, String *s);
    static void print(const std::string &str, ArrayList<Object *> *a);
};


#endif //PYVM_PRINT_HPP
