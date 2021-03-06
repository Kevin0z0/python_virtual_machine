/**
 * Created by zkw on 2021-04-09.
 */

#include "ArrayList.hpp"

template<typename T>
void ArrayList<T>::expand() {
    T *newArray = new T[_length << 1];
    for(int i = 0; i < _length; i++){
        newArray[i] = _array[i];
    }
    delete[] _array;
    _array = newArray;

    _length <<= 1;
    printf("expand an array to %d, size is %d\n", _length, _size);
}

template<typename T>
ArrayList<T>::ArrayList(int size):
    _length(size),
    _size(0),
    _array(new T[_length]) {}


template<typename T>
void ArrayList<T>::add(T t) {
    if(_size >= _length) expand();

    _array[_size++] = t;
}

template<typename T>
void ArrayList<T>::insert(int index, T t) {
    add(NULL);
    for(int i = _size; i > index; i--){
        _array[i] = _array[i - 1];
    }
    _array[index] = t;
}

template<typename T>
T ArrayList<T>::get(int index) {
    return _array[index];
}

template<typename T>
void ArrayList<T>::set(int index, T t) {
    if(_size <= index) _size = index + 1;

    while (_size > _length) expand();

    _array[index] = t;
}

template<typename T>
int ArrayList<T>::size() {
    return _size;
}

template<typename T>
int ArrayList<T>::length() {
    return _length;
}

template<typename T>
T ArrayList<T>::pop() {
    return _array[--_size];
}

template<typename T>
void ArrayList<T>::print() {
    for(int i = 0; i < _length; i++){
        printf("%d, ",_array[i]);
    }
}

template<typename T>
ArrayList<T>::~ArrayList() {
//    if(_array){
//        delete _array;
//    }
}

