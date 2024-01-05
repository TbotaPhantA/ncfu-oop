#include <iostream>
#include <stack>
#include <vector>
#include "Point.h"
#include "MazeUtils.h"
#include "MazeUtilsTests.h"

int main() {
    runAllUnitTests();

    std::vector<std::vector<char>> maze = {
        {CLOSED, CLOSED, CLOSED, OPEN, CLOSED},
        {CLOSED, OPEN, CLOSED, OPEN, OPEN},
        {CLOSED, OPEN, OPEN, OPEN, CLOSED},
        {OPEN, OPEN, CLOSED, OPEN, OPEN},
        {CLOSED, OPEN, CLOSED, CLOSED, OPEN}
    };

    Point start(1, 1);

    std::vector<Point> path = findPath(maze, start);

    if (!path.empty()) {
        std::cout << "Found path:\n";
        for (const auto& point : path) {
            std::cout << "(" << point.row << ", " << point.col << ") ";
        }
        std::cout << "\n";
    }
    else {
        std::cout << "The path was not found.\n";
    }

    return 0;
}