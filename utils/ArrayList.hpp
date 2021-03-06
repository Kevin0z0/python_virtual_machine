/**
 * Created by zkw on 2021-04-09.
 */
#ifndef CPP_ARRAYLIST_HPP
#define CPP_ARRAYLIST_HPP
#include <cstdio>

template <typename T>
class ArrayList {
private:
    int _length;
    int _size;
    T *_array;

    void expand();
public:
    explicit ArrayList(int size = 8);
    ~ArrayList();

    T pop();
    T get(int index);

    int  size();
    int  length();

    void print();
    void add(T t);
    void set(int index, T t);
    void insert(int index, T t);
};

//强制对模板类进行实例化
class Object;
template class ArrayList<Object*>;

class String;
template class ArrayList<String*>;

class Block;
template class ArrayList<Block*>;

typedef ArrayList<Object*>* ObjList;
#endif

//CPP_ARRAYLIST_HPP
