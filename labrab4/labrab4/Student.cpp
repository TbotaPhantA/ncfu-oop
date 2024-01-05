#include <iostream>
#include <vector>
#include <cassert>
#include "Student.h"

using std::string;
using std::vector;
using std::cout;
using std::endl;

void Student::setLastName(const std::string& lastName) {
	lastname = lastName;
}

const std::string& Student::getLastName() const {
	return lastname;
}

void Student::setInitials(const std::string& initials) {
	this->initials = initials;
}

const std::string& Student::getInitials() const {
	return initials;
}

void Student::setGroupNumber(int groupNumber) {
	this->groupNumber = groupNumber;
}

int Student::getGroupNumber() const {
	return groupNumber;
}

void Student::setPerformance(const std::vector<int>& performance) {
	this->performance = performance;
}

const std::vector<int>& Student::getPerformance() const {
	return performance;
}

std::ostream& operator<<(std::ostream& os, const Student& student) {
    os << "Last Name: " << student.getLastName() << "\n";
    os << "Initials: " << student.getInitials() << "\n";
    os << "Group Number: " << student.getGroupNumber() << "\n";
    os << "Performance: ";
    for (int score : student.getPerformance()) {
        os << score << " ";
    }
    os << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, Student& student) {
    string lastname;
    string initials;
    int groupNumber;
    vector<int> performance;

    std::cout << "Enter Last Name: ";
    is >> lastname;
    std::cout << "Enter Initials: ";
    is >> initials;
    std::cout << "Enter Group Number: ";
    is >> groupNumber;
    std::cout << "Enter Performance (space-separated scores): ";
    
    performance.clear();

	std::cout << "Performance (5 grades separated by spaces): ";
	for (int j = 0; j < 5; ++j) {
		int grade;
		is >> grade;
		performance.push_back(grade);
	}

    student.setLastName(lastname);
    student.setInitials(initials);
    student.setGroupNumber(groupNumber);
    student.setPerformance(performance);
    
    return is;
}

void readStudents(std::vector<Student>& students) {
    for (int i = 0; i < 2; ++i) {
        Student student;
        std::cin >> student;
        students.push_back(student);
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void displayStudentsWithGoodGrades(const std::vector<Student>& students) {
    std::cout << "Students with good grades:" << std::endl;
    bool found = false;

    for (const auto& student : students) {
        const std::vector<int>& performance = student.getPerformance();

        bool hasGoodGrades = true;

        for (int grade : performance) {
            if (grade < 4) {
                hasGoodGrades = false;
                break;
            }
        }

        if (hasGoodGrades) {
            std::cout << student;
            found = true;
        }
    }

    if (!found) {
        std::cout << "No students with good grades found!" << std::endl;
    }
}
