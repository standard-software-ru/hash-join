#include "HashTable.hpp"

HashTable::~HashTable()
{
    for (int i = 0; i < BLOCKS_QUANTITY; i++)
    {
        if (blocks[i] != nullptr) delete blocks[i];
    }
}

/**
 * Insert the value into the hash table
 */
void HashTable::insert(int key, int value)
{
    int hashedKey = HashFunction::run(key);

    if (blocks[hashedKey] == nullptr)
    {
        blocks[hashedKey] = new LinkedList<int, int>();
    }

    blocks[hashedKey]->push(key, value);
}

/**
 * Get value by key
 */
int HashTable::get(int key)
{
    int hashedKey = HashFunction::run(key);

    if (blocks[hashedKey] == nullptr) return NOT_FOUND;

    return blocks[hashedKey]->findByKey(key);
}
