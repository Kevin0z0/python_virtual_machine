//
// Created by zkw on 2021-04-21.
//

#include "FrameObject.hpp"

FrameObject::FrameObject() = default;

/**
 * 初始化时加载，可理解为main函数
 * @param codes
 */
FrameObject::FrameObject(CodeObject *codes) :
    _consts(codes->_consts),
    _names(codes->_names),
    _locals(new Map<Object *, Object *>),
    _stack(new ArrayList<Object *>()),
    _loopStack(new ArrayList<Block *>()),
    _codes(codes),
    _pc(0),
    _globals(_locals) //非函数的上下文中，局部变量和全局变量作用一样
    {}

/**
 * 创建新函数
 * @param func
 */
FrameObject::FrameObject(FunctionObject *func, ObjList args) : _codes(func->_funcCode){
    _consts     = _codes->_consts;
    _names      = _codes->_names;
    _loopStack  = new ArrayList<Block*>();
    _locals     = new Map<Object *, Object *>;
    _pc         = 0;
    _sender     = nullptr;
    _stack      = new ArrayList<Object *>();
    _globals    = func->_globals; //新的栈帧会载入全局变量

    _fastLocals = nullptr;

    if(func->_defaults){
        _fastLocals = new ArrayList<Object *>;
        int defaultArgs = func->_defaults->size();
        int argsNum = _codes->_argCount;

        while(defaultArgs--){
            _fastLocals->set(--argsNum, func->_defaults->get(defaultArgs));
        }
    }

    if(args){
        if(!_fastLocals) _fastLocals = new ArrayList<Object *>;

        for(int i = 0; i < args->size(); i++){
            _fastLocals->set(i, args->get(i));
        }
    }
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


