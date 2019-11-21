#include "ChainingHashTable.h"
///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
ChainingHashTable::ChainingHashTable() {
	
	table = new std::list<pair>[capacity];
}

// destructor
ChainingHashTable::~ChainingHashTable() {
	delete[] table;
}

// inserts the given string key
void ChainingHashTable::insert(std::string key, int val) {
	if (table[hash(key)].size() == 0) {
		pair tempPair;
		tempPair.key = key;
		tempPair.val = 1;
		
		table[hash(key)].push_back(tempPair);
	}
	else  {
		int index = hash(key);
		std::list<pair>::iterator it;
		for(it = table[index].begin(); it != table[index].end(); it++) { //loops through to check and see if the key is already in the linked list
			if(it->key == key) {
				it->val = it->val + 1;
				return;
			}
		}
		pair tempPair;
		tempPair.key = key;
		tempPair.val = 1;
		table[index].push_back(tempPair);
	}
	
	
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ChainingHashTable::remove(std::string key) {
	int index = hash(key);
	std::list<pair>::iterator it;
	for(it = table[index].begin(); it != table[index].end(); it++) {
		if(it->key == key) {
			int value = it->val;
			table[index].erase(it);
			return value;
		}
	}

	std::cout << "key not found" << std::endl;
}

// getter to obtain the value associated with the given key
int ChainingHashTable::get(std::string key) {
	int index = hash(key);
	if(table[index].size() != 0) {
		std::list<pair>::iterator it;
		for(it = table[index].begin(); it != table[index].end(); it++) {
			if(it->key == key) {
				return it->val;
			}
		}
	} 
	
	
}

// prints number of occurrances for all given strings to a txt file
void ChainingHashTable::printAll(std::string filename) {
	std::string line;
	std::ifstream myfile (filename);
	std::vector<std::string> key; 
	if (myfile.is_open())
	{
		while ( getline (myfile,line) )
		{
			std::string tempKey = line;
			key.push_back(tempKey);
			insert(tempKey, 1);
		}
		myfile.close();
	}
	std::ofstream ofs ("ChainingHash.txt", std::ofstream::out);

	for(int i = 0; i < capacity; i++) {
		std::list<pair>::iterator it;
		for(it = table[i].begin(); it != table[i].end(); it++) {
			ofs << it->key << " " <<it->val << std::endl;
		}
	}
	ofs.close();
	
}