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
    MapEntry(const MapEntry<K, V>& entry);
    MapEntry(K k, V v):_key(k), _value(v){};
};

template <typename K, typename V>
class Map {
private:
    int _size;
    int _length;
    MapEntry<K, V> *_entries;

    void expand();
public:
    Map();
    explicit Map(int size);

    V get(K key);
    V remove(K key);
    int index(K key);
    bool hasKey(K key);
    K getKey(int index);
    void set(K key, V value);
    int size(){return _size;}
    MapEntry<K, V> *entries(){ return _entries; }
};

#endif //CPP_MAP_HPP
