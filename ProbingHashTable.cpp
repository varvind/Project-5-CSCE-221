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
	int index = hash(key);
	if(table[index].key == "" ) {
		pair temp;
		temp.val = temp.val + 1;
		temp.key = key;

		table[index] = temp;
	}
	else if ( table[index].key == key) { //increments if key matches
		table[index].val = table[index].val + 1;
	}
	else { //if key is hashed to same index as another element, loops until there is an available spot
		for(int i = index; i < capacity; i++) {
			if(table[index].key == "") { //signifying that this index in the table is available
				pair temp;
				temp.val = temp.val + 1;
				temp.key = key;

				table[index] = temp;
				break;
			}
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

	for(int i = 0; i < key.size(); i ++) {
		ofs << key.at(i) << ": " << get(key.at(i)) << std::endl;
	}
	ofs.close();
}