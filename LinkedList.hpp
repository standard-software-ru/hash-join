#pragma once

#include "Node.hpp"

/**
 * LinkedList
 *
 * @author Standard Software standard.software.ru@gmail.com
 */
template<typename K, typename T>
class LinkedList
{
private:
    /**
     * First element in the LinkedList
     */
    Node<K, T>* root;

    /**
     * Size of the LinkedList
     */
    size_t size;
public:
    LinkedList() : root(nullptr), size(0)
    {}

    ~LinkedList()
    {
        while (size--)
        {
            popFront();
        }
    }

    /**
     * Push to the LinkedList
     */
    void push(K key, T value)
    {
        Node<K, T>* node = new Node<K, T>(key, value);
        Node<K, T>* current = root;

        if (current == nullptr)
        {
            root = node;
            size++;
            return;
        }

        while (current->next != nullptr)
        {
            current = current->next;
        }

        current->next = node;
        size++;
    }

    /**
     * Pop the first node from the LinkedList
     */
    T popFront()
    {
        if (!size) return T();
        Node<K, T>* current = root;
        T value = current->value;

        root = root->next;
        delete current;
        size--;

        return value;
    }

    /**
     * Find value by key
     */
    T findByKey(K key)
    {
        Node<K, T>* current = root;

        while (current != nullptr)
        {
            if (current->key == key) return current->value;
            current = current->next;
        }

        return T();
    }

    /**
     * Get size
     */
    size_t getSize()
    {
        return size;
    }
};