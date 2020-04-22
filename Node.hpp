#pragma once

/**
 * Node in LinkedList
 *
 * @author Standard Software standard.software.ru@gmail.com
 */
template<typename K, typename T>
class Node
{
public:
    K key;
    T value;
    Node<K, T>* next;

    Node(T key, T value = T(), Node<K, T>* next = nullptr) :
    key(key), value(value), next(next)
    {}
};