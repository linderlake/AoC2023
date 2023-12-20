#pragma once
#include <string>
#include <vector>

struct Node {
  int x;
  int y;
  int weight;
  Node(int x, int y, int weight);
  virtual ~Node() = default;
};

struct Galaxy : Node {
  Galaxy(int x, int y);
};

bool RowIsEmpty(const std::vector<std::string>& input, size_t y);
bool ColumnIsEmpty(const std::vector<std::string>& input, size_t x);
void DuplicateEmptyRowsAndColumns(std::vector<std::string>& input);
void MarkEmptyRowsAndColumns(std::vector<std::string>& input);
std::vector<std::pair<Galaxy*, Galaxy*>>
GetPairs(std::vector<Galaxy>& galaxies);
std::vector<std::pair<Galaxy*, Galaxy*>>
GetPairs(std::vector<Galaxy*>& galaxies);