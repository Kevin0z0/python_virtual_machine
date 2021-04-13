//
// Created by zkw on 2021-04-13.
//

#ifndef CPP_MAP_HPP
#define CPP_MAP_HPP
template <typename K, typename V>
class MapEntry{
public:
    K _key;
    V _value;

    MapEntry():_key(0), _value(0){};
    MapEntry(K k, V v):_key(k), _value(v){};
    MapEntry(const MapEntry<K, V>& entry);
};

template <typename K, typename V>
class Map {
private:
    MapEntry<K, V> *_entries;
    int _size;
    int _length;

    void expand();
public:
    Map();

    int size(){return _size;}
    void put(K key, V value);
    V get(K key);
    K getKey(int index);
    bool hasKey(K key);
    V remove(K key);
    int index(K key);
    MapEntry<K, V> *entries(){ return _entries; }
};


#endif //CPP_MAP_HPP
