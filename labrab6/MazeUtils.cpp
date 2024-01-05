#include <iostream>
#include <stack>
#include <vector>
#include "Point.h"
#include "MazeUtils.h"

bool isValid(const std::vector<std::vector<char>>& maze, int row, int col) {
    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && maze[row][col] == OPEN) {
        return true;
    }
    return false;
}

std::vector<Point> findPath(const std::vector<std::vector<char>>& maze, Point start) {
    std::vector<Point> path;
    std::stack<Point> stack;
    std::vector<std::vector<char>> tempMaze = maze;

    stack.push(start);

    while (!stack.empty()) {
        Point current = stack.top();
        stack.pop();
        path.push_back(current);

        if (current.row == ROWS - 1 && current.col == COLS - 1) {
            return path;
        }

        tempMaze[current.row][current.col] = CLOSED;

        if (isValid(tempMaze, current.row - 1, current.col)) {
            stack.push(Point(current.row - 1, current.col));
        }
        if (isValid(tempMaze, current.row + 1, current.col)) {
            stack.push(Point(current.row + 1, current.col));
        }
        if (isValid(tempMaze, current.row, current.col - 1)) {
            stack.push(Point(current.row, current.col - 1));
        }
        if (isValid(tempMaze, current.row, current.col + 1)) {
            stack.push(Point(current.row, current.col + 1));
        }
    }

    return {};
}
