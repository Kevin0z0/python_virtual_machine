//
// Created by zkw on 2021-04-10.
//

#ifndef CPP_CODEOBJECT_HPP
#define CPP_CODEOBJECT_HPP
#include "../object/String.hpp"
#include "../utils/ArrayList.hpp"

class CodeObject : public Object{
public:
    CodeObject(int argCount,
               int nLocals,
               int stackSize,
               int flag,
               String *bytecodes,
               ArrayList<Object*>* consts,
               ArrayList<Object*>* names,
               ArrayList<Object*>* varNames,
               ArrayList<Object*>* freevars,
               ArrayList<Object*>* cellvars,
               String *filename,
               String *coName,
               int lineNo,
               String *notable
    );

    int _argCount;
    int _nLocals;
    int _stackSize;
    int _flag;
    String *_bytecodes;
    ArrayList<Object*>* _consts;
    ArrayList<Object*>* _names;
    ArrayList<Object*>* _varNames;
    ArrayList<Object*>* _freevars;
    ArrayList<Object*>* _cellvars;
    String *_filename;
    String *_coName;
    int _lineNo;
    String *_notable;
};


#endif //CPP_CODEOBJECT_HPP
