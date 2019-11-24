#include "DoubleHashTable.h"

///////////////////// TODO: FILL OUT THE FUNCTIONS /////////////////////

// constructor (NOTE: graders will use a default constructor for testing)
DoubleHashTable::DoubleHashTable() {
	table = new pair[capacity];
}

// destructor
DoubleHashTable::~DoubleHashTable() {
	delete[] table;
}

// inserts the given string key
void DoubleHashTable::insert(std::string key, int val) {
	for(int i = 0; i < capacity; i++) {
		int index = hash(key) + (i * (secondHash(key)));
		
		if(table[index].key == "") {
			pair temp;
			temp.key = key;
			temp.val = 1;
			table[index] = temp;
			break;
		}
		if(table[index].key == key) {
			table[index].val = table[index].val + 1;
			break;
		}
	}
}

// removes the given key from the hash table - if the key is not in the list, throw an error
int DoubleHashTable::remove(std::string key) {
	
	
	for(int i = 0; i < capacity; i++) {
		int index = hash(key) + i * (secondHash(key));
		if(table[index].key == key) {
			
			table[index].key = "";
			table[index].val = 0;
			return index;
		}
		if(table[index].key == "") {
			return 0;
		}
	}
	return 0;
}

// getter to obtain the value associated with the given key
int DoubleHashTable::get(std::string key) {

	for(int i = 0; i < capacity; i++) {
		int index = hash(key) + (i * (secondHash(key)));
		
		if(table[index].key == key) {
			
			return table[index].val;
		}
		if(table[index].key == "") {
			return 0;
		}
	}
}

// prints number of occurrances for all given strings to a txt file
void DoubleHashTable::printAll(std::string filename) {
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
	std::ofstream ofs ("DoubleHashing.txt", std::ofstream::out);

	for(int i = 0; i < capacity; i ++) {
		if(table[i].key != "") {
			ofs << table[i].key << ": " << get(table[i].key) << std::endl;
		}
		
	}
	ofs.close();
}

// helper functions 
int DoubleHashTable::secondHash(std::string s) {
	int hash = 0;
	int n = s.size();
	for(int i = 0; i < n; i++) {
		hash += int(s.at(i));
	}


	return hash ;
}
