#include <iostream>
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
#include <chrono> 
using namespace std;





int main() {
    ProbingHashTable* test = new ProbingHashTable();
    string filename = "dictionary.txt";
    //test->printAll(filename);
    cout << "Enter filename ";
    cin >> filename;
    int pushes = 10100;
    std::string line;
	std::ifstream myfile (filename);
	std::vector<std::string> key; 
    auto start = std::chrono::high_resolution_clock::now();
    
        if (myfile.is_open())
        {
            for(int i = 0; i < pushes; i++) 
            {
                getline (myfile,line); 
                std::string tempKey = line;
                key.push_back(tempKey);
                test->insert(tempKey, 1);
            }
            myfile.close();
        }
  //Heavy computation tasks here
    auto finish = std::chrono::high_resolution_clock::now();
    auto elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " nano seconds\n";
	
}