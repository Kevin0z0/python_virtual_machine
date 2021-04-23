//
// Created by zkw on 2021-04-21.
//

#ifndef PYVM_FRAMEOBJECT_HPP
#define PYVM_FRAMEOBJECT_HPP
#include "code/CodeObject.hpp"
#include "utils/Map.hpp"
#include "FunctionObject.hpp"

class FrameObject {
private:
    ArrayList<Object *>* _stack       {};
    ArrayList<Block  *>* _loopStack   {};
    ArrayList<Object *>* _consts      {};
    ArrayList<Object *>* _names       {};

    Map<Object *, Object *>  *_locals {};
    CodeObject               *_codes  {};
    unsigned int             _pc      {};
    FrameObject              *_sender {};
public:

    explicit FrameObject(CodeObject *codes);
    explicit FrameObject(FunctionObject *callable);
    FrameObject();

    void setPC(unsigned int x)           { _pc = x;           }
    void setSender(FrameObject *x)       { _sender = x;       }
    unsigned int  getPC()   const        { return _pc;        }
    ArrayList<Object *>     *stack()     { return _stack;     }
    ArrayList<Block  *>     *loopStack() { return _loopStack; }
    ArrayList<Object *>     *consts()    { return _consts;    }
    ArrayList<Object *>     *names()     { return _names;     }
    Map<Object *, Object *> *locals()    { return _locals;    }
    FrameObject             *sender()    { return _sender;    }

    bool hasMoreCodes();
    unsigned char getOpCode();
    int getOpArg();
    bool isFirstFrame(){ return _sender == nullptr; }
};


#endif //PYVM_FRAMEOBJECT_HPP
