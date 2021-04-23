//
// Created by zkw on 2021-04-13.
//

#include "Map.hpp"
#include "runtime/Universe.hpp"

template<typename K, typename V>
MapEntry<K, V>::MapEntry(const MapEntry<K, V> &entry) :
    _key(entry._key),
    _value(entry._value){}

template<typename K, typename V>
void Map<K, V>::expand() {
    if(_size >= _length){
        auto *newEntry = new MapEntry<K, V>[_length << 1];
        for(int i = 0; i < _size; i++){
            newEntry[i] = _entries[i];
        }
        _length <<= 1;
        delete [] _entries;
        _entries = newEntry;
    }
}

template<typename K, typename V>
Map<K, V>::Map() :
    _entries(new MapEntry<K, V>[8]),
    _size(0),
    _length(8) {}

template<typename K, typename V>
Map<K, V>::Map(int len) :
    _entries(new MapEntry<K, V>[8]),
    _size(0),
    _length(len) {}

template<typename K, typename V>
void Map<K, V>::set(K key, V value) {
    for(int i = 0; i < _size; i++){
        if(_entries[i]._key->equal(key) == Universe::True){
            _entries[i]._value = value;
            return;
        }
    }
    expand();
    _entries[_size++] = MapEntry<K, V>(key, value);
}

template<typename K, typename V>
V Map<K, V>::get(K key) {
    int i = index(key);
    if(i < 0)
        return Universe::None;
    return _entries[i]._value;
}

template<typename K, typename V>
K Map<K, V>::getKey(int index) {
    return _entries[index]._key;
}

template<typename K, typename V>
bool Map<K, V>::hasKey(K key) {
    return index(key) > 0;
}

template<typename K, typename V>
V Map<K, V>::remove(K key) {
    int i = index(key);
    if(i < 0) return 0;
    V val = _entries[i]._value;
    _entries[i] = _entries[--_size]; //Map无序排列，只需将要删除的键值对与最后一个键值对交换即可，学到了学到了
    return val;
}

template<typename K, typename V>
int Map<K, V>::index(K key) {
    for(int i = 0; i < _size; i++){
        if(_entries[i]._key->equal(key) == Universe::True)
            return i;
    }
    return -1;
}

template class Map<Object*, Object*>;

