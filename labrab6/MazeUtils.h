#pragma once

#include <iostream>
#include <stack>
#include <vector>
#include "Point.h"

const int ROWS = 5;
const int COLS = 5;
const char OPEN = '.';
const char CLOSED = '#';

std::vector<Point> findPath(const std::vector<std::vector<char>>& maze, Point start);
