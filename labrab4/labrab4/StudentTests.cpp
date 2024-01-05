#include <iostream>
#include <vector>
#include <cassert>
#include "Student.h"
#include "StudentTests.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

void testSetLastName() {
    Student student;
    student.setLastName("Smith");
    assert(student.getLastName() == "Smith");
    cout << "testSetLastName is successful" << endl;
}

void testSetInitials() {
    Student student;
    student.setInitials("J.D.");
    assert(student.getInitials() == "J.D.");
    cout << "testSetInitials is successful" << endl;
}

void testSetGroupNumber() {
    Student student;
    student.setGroupNumber(42);
    assert(student.getGroupNumber() == 42);
    cout << "testSetGroupNumber is successful" << endl;
}

void testSetPerformance() {
    Student student;
    std::vector<int> performance{ 90, 85, 95 };
    student.setPerformance(performance);
    assert(student.getPerformance() == performance);
    cout << "testSetPerformance is successful" << endl;
}

void runUnitTests() {
    testSetLastName();
    testSetGroupNumber();
    testSetPerformance();
    cout << "All unit tests are successful" << endl;
}
