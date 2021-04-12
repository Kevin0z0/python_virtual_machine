#include <string>
#include <iostream>
#include "utils/BufferedInputStream.hpp"
#include "object/String.hpp"
#include "code/BinaryFileParser.hpp"
#include "runtime/Interpreter.hpp"

void printString(const std::string& str,String *s){
    std::cout << str << *s << std::endl;
}

//printf("argCount: %d\n", mainCode->_argCount);
//printf("nLocals: %d\n", mainCode->_nLocals);
//printf("stackSize: %d\n", mainCode->_stackSize);
//printf("flags: 0x%x\n", mainCode->_flag);
//printString("bytecodes: ", mainCode->_bytecodes);
//printf("consts: %x\n", mainCode->_consts);
//printf("names: %x\n", mainCode->_names);
//printf("varNames: %x\n", mainCode->_varNames);
//printf("freevars: %x\n", mainCode->_freevars);
//printf("cellvars: %x\n", mainCode->_cellvars);
//printString("filename: ", mainCode->_filename);
//printString("moduleName: ", mainCode->_coName);

int main() {
    char path[] = R"(C:\Users\zkw\Desktop\cpp\test_if.pyc)";
    BufferedInputStream stream(path);
    BinaryFileParser bfp(&stream);
    CodeObject *mainCode = bfp.parse();
    Interpreter interpreter{};
    interpreter.run(mainCode);
    return 0;
}
