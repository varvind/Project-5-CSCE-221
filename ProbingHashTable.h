#ifndef LINEARPROBING_H
#define LINEARPROBING_H

#include <list>
#include "HashTable.h"
#include <vector>
// Linear probing hash table class
class ProbingHashTable : public HashTable {
    private:
    pair* table;

    public: 
    ProbingHashTable();
    ~ProbingHashTable(); 
    void insert(std::string key, int val); 
    int remove(std::string key); 
    int get(std::string key); 
    void printAll(std::string filename);
};

#endif