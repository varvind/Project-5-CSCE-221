#include "ChainingHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	
	table = new std::list<int>[capacity];
}

// destructor
ChainingHashTable::~ChainingHashTable() {
	delete[] table;
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	std::list<int> temp = {val};
	table[hash(key)] = temp;
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	int value = 0;
	if(table[hash(key)].size() == 0) {
		std::cout << "Inesert Exception here" << std::endl;
		return 0;
 	}
	else {
		value = get(key);
		table[hash(key)].clear();
	}
	return value;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {

	return table[hash(key)].size();
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {

}