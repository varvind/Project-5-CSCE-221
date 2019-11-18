#ifndef CHAINING_H
#define CHAINING_H

#include <list>
#include "HashTable.h"


// Chaining hash table class
class ChainingHashTable: public HashTable {
    private:
    // TODO: insert additional variables needed here
    std::list<int>* table;


    public: 
    ChainingHashTable();
    ~ChainingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key);
    void printAll(std::string filename);
};

#endif