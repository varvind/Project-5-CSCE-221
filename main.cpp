#include <iostream>
#include "ChainingHashTable.h"
#include "ProbingHashTable.h"
using namespace std;





int main() {
    ProbingHashTable* test = new ProbingHashTable();
    test->printAll("test.txt");
}