#pragma once

#include "LinkedList.hpp"
#include "HashFunction.hpp"

#define BLOCKS_QUANTITY 1024
#define NOT_FOUND 0

/**
 * Hash table
 *
 * @author Standard Software standard.software.ru@gmail.com
 */
class HashTable
{
private:
    /**
     * Blocks of the hash table
     */
    LinkedList<int, int>* blocks[BLOCKS_QUANTITY] = {nullptr};
public:
    ~HashTable();

    /**
     * Insert the value into the hash table
     */
    void insert(int key, int value);

    /**
     * Get value by key
     */
    int get(int key);
};