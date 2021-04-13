//
// Created by zkw on 2021-04-13.
//

#include "Map.hpp"
template<typename K, typename V>
MapEntry<K, V>::MapEntry(const MapEntry<K, V> &entry) {

}

template<typename K, typename V>
void Map<K, V>::expand() {

}

template<typename K, typename V>
Map<K, V>::Map() : _size(0),_length(0) {

}

template<typename K, typename V>
void Map<K, V>::put(K key, V value) {

}

template<typename K, typename V>
V Map<K, V>::get(K key) {
    return nullptr;
}

template<typename K, typename V>
K Map<K, V>::getKey(int index) {
    return nullptr;
}

template<typename K, typename V>
bool Map<K, V>::hasKey(K key) {
    return false;
}

template<typename K, typename V>
V Map<K, V>::remove(K key) {
    return nullptr;
}

template<typename K, typename V>
int Map<K, V>::index(K key) {
    return 0;
}
