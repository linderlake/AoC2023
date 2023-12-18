#include "solutions.h"
#include "placeholder.h"
#include <iostream>
#include <numeric>
#include <queue>
#include <unordered_set>

int PartOne(std::vector<std::string> input) {
  int answer{};
  std::vector<Galaxy> galaxies;
  DuplicateEmptyRowsAndColumns(input);
  for (size_t y{0}; y < input.size(); y++) {
    const auto& row{input.at(y)};
    for (size_t x{0}; x < row.size(); x++) {
      if (row.at(x) == '#') {
        galaxies.emplace_back(Galaxy{static_cast<int>(x), static_cast<int>(y)});
      }
    }
  }

  auto pairs{GetPairs(galaxies)};
  for (const auto& pair : pairs) {
    const auto& [galaxy1, galaxy2] = pair;
    const auto& [x1, y1] = *galaxy1;
    const auto& [x2, y2] = *galaxy2;
    int x_diff{x2 - x1};
    int y_diff{y2 - y1};
    int x_step{0};
    int y_step{0};
    if (x_diff != 0) {
      x_step = x_diff / std::gcd(x_diff, y_diff);
    }
    if (y_diff != 0) {
      y_step = y_diff / std::gcd(x_diff, y_diff);
    }
    int x{x1};
    int y{y1};
    while (x != x2 || y != y2) {
      int prev_x = x;
      int prev_y = y;
      x += x_step;
      y += y_step;
      answer += std::abs((x - prev_x)) + std::abs((y - prev_y));
    }
  }
  return answer;
}

int PartTwo(std::vector<std::string> input) {
  int answer{};
  std::vector<Galaxy> galaxies;
  DuplicateEmptyRowsAndColumns(input);
  for (size_t y{0}; y < input.size(); y++) {
    const auto& row{input.at(y)};
    for (size_t x{0}; x < row.size(); x++) {
      if (row.at(x) == '#') {
        galaxies.emplace_back(Galaxy{static_cast<int>(x), static_cast<int>(y)});
      }
    }
  }

  auto pairs{GetPairs(galaxies)};
  for (const auto& pair : pairs) {
    const auto& [galaxy1, galaxy2] = pair;
    const auto& [x1, y1] = *galaxy1;
    const auto& [x2, y2] = *galaxy2;
    int x_diff{x2 - x1};
    int y_diff{y2 - y1};
    int x_step{0};
    int y_step{0};
    if (x_diff != 0) {
      x_step = x_diff / std::gcd(x_diff, y_diff);
    }
    if (y_diff != 0) {
      y_step = y_diff / std::gcd(x_diff, y_diff);
    }
    int x{x1};
    int y{y1};
    while (x != x2 || y != y2) {
      int prev_x = x;
      int prev_y = y;
      x += x_step;
      y += y_step;
      answer += std::abs((x - prev_x)) + std::abs((y - prev_y));
    }
  }
  return answer;
  return answer;
}
