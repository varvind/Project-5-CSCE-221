#include "ProbingHashTable.h"

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	table = new std::string[capacity];
}

// destructor
ProbingHashTable::~ProbingHashTable() {
	delete[] table;
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	int index = hash(key);
	if(table[index] != key) {
		table[index] = key;
	}
	else {
		for(int i = index + 1; i < capacity; i++) {
			if(table[index] != key) {
				table[index] = key;
				break;
			}
		}
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	if(table[hash(key)] != key) {
		std::cout << "Write an Exception here Arvind" << std::endl;
		return;
	}
	else {
		for(int i = hash(key) ; i < capacity; i++) {
			if(table[hash(key)] != key) {
				break;
			}
			else {
				table[i] == ""; //removing current by just putting empty string as placeholder
			}
		}
	}
	
}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {

}