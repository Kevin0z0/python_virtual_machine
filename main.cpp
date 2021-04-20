#include <string>
#include <iostream>
#include "utils/BufferedInputStream.hpp"
//#include "object/String.hpp"
#include "code/BinaryFileParser.hpp"

#include "runtime/Interpreter.hpp"

void printByte(const std::string &str, String *s) {
    std::cout << str;
    for(int i = 0; i < s->length(); i++){
        printf("%x",s->value()[i]);
    }
    printf("\n");
}

void print(const std::string &str, String *s) {
    std::cout << str;
    s->print();
    printf("\n");
}

void print(const std::string &str, ArrayList<Object *> *a) {
    std::cout << str << "(";
    int len = a->length();
    for (int i = 0; i < len; i++) {
        a->get(i)->print();
        if(i != len - 1) printf(", ");
    }
    printf(")\n");
}

void printInfo(CodeObject* mainCode){
    printf("argCount: %d\n", mainCode->_argCount);
    printf("nLocals: %d\n", mainCode->_nLocals);
    printf("stackSize: %d\n", mainCode->_stackSize);
    printf("flags: 0x%x\n", mainCode->_flag);
    printByte("bytecodes: ", mainCode->_bytecodes);
    print("consts: ", mainCode->_consts);
    print("names: ", mainCode->_names);
    print("varNames: ", mainCode->_varNames);
    print("freevars: ", mainCode->_freevars);
    print("cellvars: ", mainCode->_cellvars);
    print("filename: ", mainCode->_filename);
    print("moduleName: ", mainCode->_coName);
}

int main() {
    char path[] = R"(C:\Users\zkw\Desktop\python_virtual_machine\__pycache__\test_var.pyc)";
    BufferedInputStream stream(path);
    BinaryFileParser bfp(&stream);
    CodeObject *mainCode = bfp.parse();
    printInfo(mainCode);
    Interpreter interpreter{};
    interpreter.run(mainCode);
    return 0;
}
