//
// Created by zkw on 2021-04-10.
//

#ifndef CPP_BINARYFILEPARSER_HPP
#define CPP_BINARYFILEPARSER_HPP
#include "../utils/BufferedInputStream.hpp"
#include "CodeObject.hpp"

class BinaryFileParser {
private:
    BufferedInputStream *fileStream;
    ArrayList<String*> _string_table;

public:
    explicit BinaryFileParser(BufferedInputStream *stream);
    ~BinaryFileParser();
    CodeObject *parse();
    CodeObject *getCodeObject();
    String *getByteObject();
    String *getString();
    ArrayList<Object*> *getConsts();
    ArrayList<Object*> *getTuple();
    ArrayList<Object*> *getNames();
    ArrayList<Object*> *getVarNames();
    ArrayList<Object*> *getFreeVars();
    ArrayList<Object*> *getCellVars();
    String *getFileName();
    String *getName();
    String *getNotable();
};


#endif //CPP_BINARYFILEPARSER_HPP
