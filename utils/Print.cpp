//
// Created by zkw on 2021/4/23.
//

#include "Print.hpp"

int Print::indent = -1;

void Print::printIndent() {
    for(int i = 0; i < indent; i++) printf("    ");
}

Print::Print(CodeObject *mainCode) {
    indent++;
    print("<CodeObject>");
    indent++;
    print("argCount: "     ,  mainCode->_argCount  );
    print("nLocals: "      ,  mainCode->_nLocals   );
    print("stackSize: "    ,  mainCode->_stackSize );
    print("flags: 0x"      ,  mainCode->_flag      );
    printByte("bytecodes: ",  mainCode->_bytecodes );
    print("consts: "       ,  mainCode->_consts    );
    print("names: "        ,  mainCode->_names     );
    print("varNames: "     ,  mainCode->_varNames  );
    print("freevars: "     ,  mainCode->_freevars  );
    print("cellvars: "     ,  mainCode->_cellvars  );
    print("filename: "     ,  mainCode->_filename  );
    print("moduleName: "   ,  mainCode->_coName    );
    indent--;
    print("</CodeObject>");
    indent--;
    printIndent();
}

void Print::print(const std::string &str) {
    printIndent();
    std::cout << str << std::endl;
}

void Print::print(const std::string &str, int t) {
    printIndent();
    std::cout << str;
    printf("%d\n", t);
}

void Print::print(const std::string &str, ArrayList<Object *> *a) {
    printIndent();
    std::cout << str << "(";
    int len = a->size();
    if(len >= 1){
        a->get(0)->print();
    }
    for (int i = 1; i < len; i++) {
        printf(", ");
        a->get(i)->print();
    }
    printf(")\n");
}


void Print::print(const std::string &str, String *s) {
    printIndent();
    std::cout << str;
    s->print();
    printf("\n");
}

void Print::printByte(const std::string &str, String *s) {
    printIndent();
    std::cout << str;
    for(int i = 0; i < s->length(); i++)
        printf("%x",s->value()[i]);
    printf("\n");
}
