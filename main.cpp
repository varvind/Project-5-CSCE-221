#include <iostream>
#include "ChainingHashTable.h"
using namespace std;





int main() {
    ChainingHashTable* test = new ChainingHashTable();


    test->insert("hello", 1);
    test->insert("hello", 1);
    test->insert("hello", 1);
    cout << test->get("hello");

    
}