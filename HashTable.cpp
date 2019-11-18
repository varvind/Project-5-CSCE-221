#include "HashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// default constructor
HashTable::HashTable() {
	capacity = 1000000;
}

// destructor
HashTable::~HashTable() {
}

// hash function to determine index where string key goes, as mentioned in the instructions
int HashTable::hash(std::string s) {

	int hash = 0;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		hash = 2 *(hash) +  int(s.at(i));
	}
	int index = hash % capacity;
	return index;
}

// returns a boolean of whether the hash table is empty or not
bool HashTable::isEmpty() const {
	
	return false;
}
