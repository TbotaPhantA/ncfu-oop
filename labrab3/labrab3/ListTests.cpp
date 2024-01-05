#include <cassert>
#include <iostream>
#include <stdexcept>
#include "List.h"

using std::cout;
using std::endl;

void testInsert() {
    List<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Assert that the size is correct
    assert(list.getSize() == 3);

    // Assert that the values are inserted in the correct order
    assert(list.getHead()->data == 10);
    assert(list.getHead()->next->data == 20);
    assert(list.getHead()->next->next->data == 30);

    cout << "insert tests are successful!" << endl;
}

void testRemove() {
    List<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);

    // Remove a value from the list
    bool removed = list.remove(20);

    // Assert that the value is removed correctly
    assert(removed);
    assert(list.getSize() == 2);

    // Assert that the remaining values are in the correct order
    assert(list.getHead()->data == 10);
    assert(list.getHead()->next->data == 30);

    cout << "remove tests are successful!" << endl;
}


// unit tests
void runUnitTests() {
    testInsert();
    testRemove();

    cout << "unit tests are successful" << endl;
}
