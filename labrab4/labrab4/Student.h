#pragma once

#include <iostream>
#include <vector>
#include <cassert>
using std::string;
using std::vector;
using std::cout;
using std::endl;

class Student {
    string lastname;
    string initials;
    int groupNumber;
    vector<int> performance;

public:
    void setLastName(const std::string& lastName);
    const std::string& getLastName() const;
    void setInitials(const std::string& initials);
    const std::string& getInitials() const;
    void setGroupNumber(int groupNumber);
    int getGroupNumber() const;
    void setPerformance(const std::vector<int>& performance);
    const std::vector<int>& getPerformance() const;

    friend std::ostream& operator<<(std::ostream& os, const Student& student);
    friend std::istream& operator>>(std::istream& is, Student& student);
};

void readStudents(std::vector<Student>& students);
void displayStudentsWithGoodGrades(const std::vector<Student>& students);

