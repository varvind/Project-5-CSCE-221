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
	if (table[hash(key)].size() == 0) {
		std::list<int> temp = {val};
		table[hash(key)] = temp;
	}
	else  {
		table[hash(key)].push_back(val);
	}
	
	
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
	if(table[hash(key)].size() == 0) {
		std::cout << "Insert Exception here" << std::endl;
		return 0;
 	}
	else {
		return table[hash(key)].size();
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

	for(int i = 0; i < key.size(); i ++) {
		ofs << key.at(i) << ": " << get(key.at(i)) << std::endl;
	}
	ofs.close();
	
}