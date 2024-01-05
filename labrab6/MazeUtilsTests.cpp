#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include "Point.h"
#include "MazeUtils.h"
#include "MazeUtilsTests.h"

std::string vectorToString(const std::vector<Point>& vec) {
    std::string result = "[";
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        result += "(" + std::to_string(vec[i].col) + "-" + std::to_string(vec[i].row) + ")";
        if (i != vec.size() - 1) {
            result += ", ";
        }
    }
    result += "]";
    return result;
}

void assertEqual(const std::vector<Point>& actual, const std::vector<Point>& expected) {
    if (actual.size() != expected.size()) {
        std::cout << "Test failed. Path sizes do not match.\n";
        return;
    }

    for (size_t i = 0; i < actual.size(); ++i) {
        if (actual[i].row != expected[i].row || actual[i].col != expected[i].col) {
            std::cout << "Test failed. Mismatch at index " << i << "\n";
            return;
        }
    }

    std::cout << "Test passed.\n";
}

void testFindPath() {
    std::vector<std::vector<char>> maze = {
		{CLOSED, CLOSED, CLOSED, CLOSED, CLOSED},
		{CLOSED, OPEN, CLOSED, OPEN, CLOSED},
		{CLOSED, OPEN, OPEN, OPEN, CLOSED},
		{CLOSED, OPEN, CLOSED, OPEN, OPEN},
		{CLOSED, CLOSED, CLOSED, CLOSED, OPEN}
    };

    Point start(1, 1);
    std::vector<Point> expectedPath = {
        {1, 1},
        {2, 1},
        {2, 2},
        {2, 3},
        {3, 3},
        {3, 4},
        {4, 4},
    };

    std::vector<Point> actualPath = findPath(maze, start);
    assertEqual(actualPath, expectedPath);
}

void runAllUnitTests() {
    testFindPath();
}
