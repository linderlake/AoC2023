#pragma once
#include <string>
#include <vector>

struct Galaxy {
  int x;
  int y;
  Galaxy(int x, int y);
};

bool RowIsEmpty(const std::vector<std::string>& input, size_t y);
bool ColumnIsEmpty(const std::vector<std::string>& input, size_t x);
void DuplicateEmptyRowsAndColumns(std::vector<std::string>& input);
std::vector<std::pair<Galaxy*, Galaxy*>>
GetPairs(const std::vector<Galaxy>& galaxies);
