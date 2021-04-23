//
// Created by zkw on 2021-04-21.
//

#include "FrameObject.hpp"

FrameObject::FrameObject() = default;

FrameObject::FrameObject(CodeObject *codes) :
    _consts(codes->_consts),
    _names(codes->_names),
    _locals(new Map<Object *, Object *>),
    _stack(new ArrayList<Object *>()),
    _loopStack(new ArrayList<Block *>()),
    _codes(codes),
    _pc(0){}


FrameObject::FrameObject(FunctionObject *func) : _codes(func->_funcCode){
    _consts     = _codes->_consts;
    _names      = _codes->_names;
    _loopStack  = new ArrayList<Block*>();
    _locals     = new Map<Object *, Object *>;
    _pc         = 0;
    _sender     = nullptr;
    _stack      = new ArrayList<Object *>();
}


bool FrameObject::hasMoreCodes() {
    return _pc < _codes->_bytecodes->length();
}

unsigned char FrameObject::getOpCode() {
    return _codes->_bytecodes->value()[_pc++];
}

int FrameObject::getOpArg() {
    int byte1 = _codes->_bytecodes->value()[_pc++] & 0xff;
    int byte2 = _codes->_bytecodes->value()[_pc++] & 0xff;
    return byte2 << 8 | byte1;
}
