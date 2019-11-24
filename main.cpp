#include <iostream>
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
#include "DoubleHashTable.h"
using namespace std;





int main() {
    DoubleHashTable* test = new DoubleHashTable();
    test->printAll("dictionary.txt");
}