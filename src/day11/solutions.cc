#include "solutions.h"
#include "placeholder.h"
#include <iostream>

int PartOne(std::vector<std::string> input) {
  int answer{};
  size_t y = 0;
  while (y < input.size()) {
    auto& row = input.at(y);
    if (RowIsEmpty(input, y)) {
      if (y == 0) {
        input.emplace(input.begin(), std::string(row.size(), '.'));
      } else {
        input.emplace(input.begin() + y - 1, std::string(row.size(), '.'));
      }
      ++y;
    }
    ++y;
  }
  auto& row = input.at(y);
  size_t x = 0;
  while (x < row.size()) {
    if (ColumnIsEmpty(input, x)) {
      if (x == 0) {
        for (auto& row : input) {
          row.insert(row.begin(), '.');
        }
      } else {
        for (auto& row : input) {
          row.insert(row.begin() + x - 1, '.');
        }
      }
      ++x;
    }
    ++x;
  }

  // print 2d array
  for (const auto& row : input) {
    std::cout << row << std::endl;
  }
  return answer;
}

int PartTwo(std::vector<std::string> input) {
  int answer{};
  for (const auto& row : input) {
    if (row == "hej")
      answer = 1;
  }
  return answer;
}
