#include "ProbingHashTable.h"

// constructor (NOTE: graders will use a default constructor for testing)
ProbingHashTable::ProbingHashTable() {
	table = new pair[capacity];
}

// destructor
ProbingHashTable::~ProbingHashTable() {
	delete[] table;
}

// inserts the given string key
void ProbingHashTable::insert(std::string key, int val) {
	 
	
		 
	for(int i = 0; i < capacity; i++) {
		int j = (hashProbing(key) + i) % capacity;
		if(table[j].key == "") {
			table[j].key = key;
			table[j].val = 1;
			break;
		}
		if(table[j].key == key) {
			table[j].val = table[j].val + 1;
			break;
		}
	}

	
	
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int ProbingHashTable::remove(std::string key) {
	int index = hash(key);

	for(int i = index; i < capacity; i++) {
		if(table[index].key == key) {
			table[index].key = "";
			int returnVal= table[index].val;
			table[index].val = 0;
			return returnVal;
		}
	}
	std::cout << "Unable to find key" << std::endl;

}

// getter to obtain the value associated with the given key
int ProbingHashTable::get(std::string key) {
	int index = hash(key);

	for(int i = index; i < capacity; i++) {
		if(table[i].key == key) {
			return table[i].val;
		}
	}

	return 0;
}

// prints number of occurrances for all given strings to a txt file
void ProbingHashTable::printAll(std::string filename) {
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
	std::ofstream ofs ("ProbingHash.txt", std::ofstream::out);

	for(int i = 0; i < capacity; i ++) {
		if(table[i].key != "") {
			ofs << table[i].key << ": " << get(table[i].key) << std::endl;
		}
		
	}
	ofs.close();
}