//
// Created by zkw on 2021-04-10.
//
#include "iostream"
#include "BinaryFileParser.hpp"
#include "../object/Integer.hpp"
#include "../runtime/Universe.hpp"
#include <cassert>

BinaryFileParser::BinaryFileParser(BufferedInputStream *stream): fileStream(stream){}

CodeObject *BinaryFileParser::parse() {
    Universe::genesis();
    int magicNumber = fileStream->read_int();
    printf("magic number is 0x%x\n", magicNumber);
    int modDate = fileStream->read_int();
    printf("modify date is %d\n", modDate);
    unsigned char objectType = fileStream->read();
    if(objectType == 'c'){
        CodeObject *result = getCodeObject();
        printf("Parse OK!\n");
        return result;
    }

    return nullptr;
}

CodeObject *BinaryFileParser::getCodeObject() {
    int argCount = fileStream->read_int();
    int nLocals = fileStream->read_int();
    int stackSize = fileStream->read_int();
    int flags = fileStream->read_int();

    String *byteCodes = getByteObject();
    ArrayList<Object*> *consts = getConsts();
    ArrayList<Object*> *names = getNames();
    ArrayList<Object*> *varNames = getVarNames();
    ArrayList<Object*> *freeVars = getFreeVars();
    ArrayList<Object*> *cellVars = getCellVars();
    String *filename = getFileName();
    String *moduleName = getName();
    int beginLineNo = fileStream->read_int();
    String *notable = getNotable();

    return new CodeObject(
            argCount,
            nLocals,
            stackSize,
            flags,
            byteCodes,
            consts,
            names,
            varNames,
            freeVars,
            cellVars,
            filename,
            moduleName,
            beginLineNo,
            notable);
}

String *BinaryFileParser::getByteObject() {
    assert(fileStream->read() == 's');
    return getString();
}

ArrayList<Object *> *BinaryFileParser::getConsts() {
    if(fileStream->read() == '('){
        return getTuple();
    }
    fileStream->unread();
    return nullptr;
}

ArrayList<Object *> *BinaryFileParser::getTuple() {
    int length = fileStream->read_int();
    String *str;
    auto *list = new ArrayList<Object*>(length);
    for(int i = 0; i < length; i++){
        char objType = fileStream->read();

        switch (objType) {
            case 'c':
                std::cout << "got a code object" << std::endl;
                list->add(getCodeObject());
                break;
            case 'i':
                list->add(new Integer(fileStream->read_int()));
                break;
            case 'N':
                list->add(Universe::None);
                break;
            case 't':
                str = getString();
                list->add(str);
                _string_table.add(str);
                break;
            case 's':
                list->add(getString());
                break;
            case 'R':
                list->add(_string_table.get(fileStream->read_int()));
                break;
            default:
                break;
        }
    }
    return list;
}

ArrayList<Object *> *BinaryFileParser::getNames() {
    if (fileStream->read() == '(') {
        return getTuple();
    }

    fileStream->unread();
    return nullptr;
}

ArrayList<Object *> *BinaryFileParser::getVarNames() {
    if (fileStream->read() == '(') {
        return getTuple();
    }

    fileStream->unread();
    return nullptr;
}

ArrayList<Object *> *BinaryFileParser::getFreeVars() {
    if (fileStream->read() == '(') {
        return getTuple();
    }

    fileStream->unread();
    return nullptr;
}

ArrayList<Object *> *BinaryFileParser::getCellVars() {
    if (fileStream->read() == '(') {
        return getTuple();
    }

    fileStream->unread();
    return nullptr;
}

String *BinaryFileParser::getFileName() {
    return getName();
}

String *BinaryFileParser::getName() {
    char ch = fileStream->read();

    if (ch == 's') {
        return getString();
    }
    else if (ch == 't') {
        String* str = getString();
        _string_table.add(str);
        return str;
    }
    else if (ch == 'R') {
        return _string_table.get(fileStream->read_int());
    }

    return nullptr;
}

String *BinaryFileParser::getNotable() {
    char ch = fileStream->read();

    if (ch != 's' && ch != 't') {
        fileStream->unread();
        return nullptr;
    }

    return getString();
}

String *BinaryFileParser::getString() {
    int length = fileStream->read_int();
    char *strValue = new char[length];
    for(int i = 0; i < length; i++){
        strValue[i] = fileStream->read();
    }

    auto *s = new String(strValue, length);
    delete[] strValue;
    return s;
}

BinaryFileParser::~BinaryFileParser() {
//    if(fileStream){
//        delete fileStream;
//    }
}


