#include <iostream>
#include <vector>
#include <cassert>
#include "Student.h"
#include "StudentTests.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

int main()
{
    runUnitTests();
    std::vector<Student> students;
    readStudents(students);
    displayStudentsWithGoodGrades(students);
}
