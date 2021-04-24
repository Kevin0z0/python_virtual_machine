//
// Created by zkw on 2021-04-21.
//
#ifndef PYVM_FRAMEOBJECT_HPP
#define PYVM_FRAMEOBJECT_HPP
#include "utils/Map.hpp"
#include "code/CodeObject.hpp"
#include "FunctionObject.hpp"

class FrameObject {
private:
    unsigned int         _pc           {};

    ArrayList<Object *>* _stack        {};
    ArrayList<Object *>* _names        {};
    ArrayList<Object *>* _consts       {};
    ArrayList<Object *>* _fastLocals   {};
    ArrayList<Block  *>* _loopStack    {};
    Map<Object *, Object *>  *_locals  {};
    Map<Object *, Object *>  *_globals {};
    FrameObject              *_sender  {};
    CodeObject               *_codes   {};
public:
    FrameObject();
    explicit FrameObject(CodeObject *codes);
    explicit FrameObject(FunctionObject *callable, ObjList args);

    void setPC(unsigned int x)              { _pc = x;              }
    void setSender(FrameObject *x)          { _sender = x;          }
    ArrayList<Object *>     *stack       () { return _stack;        }
    ArrayList<Object *>     *names       () { return _names;        }
    ArrayList<Object *>     *consts      () { return _consts;       }
    ArrayList<Object *>     *fastLocals  () { return _fastLocals;   }
    ArrayList<Block  *>     *loopStack   () { return _loopStack;    }
    Map<Object *, Object *> *locals      () { return _locals;       }
    Map<Object *, Object *> *globals     () { return _globals;      }
    FrameObject             *sender      () { return _sender;       }


    int getOpArg();
    bool hasMoreCodes();
    unsigned char getOpCode();
    unsigned int getPC() const { return _pc; }
    bool isFirstFrame() { return _sender == nullptr; }
};


#endif //PYVM_FRAMEOBJECT_HPP
