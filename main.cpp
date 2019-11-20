#include <iostream>
#include "ChainingHashTable.h"
using namespace std;





int main() {
    ChainingHashTable* test = new ChainingHashTable();
    test->remove("hello");

    test->insert("hello", 1);
    test->insert("hello", 1);
    test->insert("hello", 1);
    test->insert("spades", 1);
    test->insert("spades", 1);
    cout << test->get("hello") << endl;
    cout << test->remove("hello") << endl;
    cout << test->get("spades") << endl;
}