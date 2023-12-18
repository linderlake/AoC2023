#include "placeholder.h"

Galaxy::Galaxy(int x, int y) : x{x}, y{y} {}

bool RowIsEmpty(const std::vector<std::string>& input, size_t y) {
  return (std::all_of(input.at(y).begin(), input.at(y).end(),
                      [](auto c) { return c == '.'; }));
}
bool ColumnIsEmpty(const std::vector<std::string>& input, size_t x) {
  return (std::all_of(input.begin(), input.end(),
                      [x](auto row) { return row.at(x) == '.'; }));
}

void DuplicateEmptyRowsAndColumns(std::vector<std::string>& input) {
  for (size_t y = 0; y < input.size(); y++) {
    if (RowIsEmpty(input, y)) {
      input.insert(input.begin() + y, input.at(y));
      y++;
    }
  }
  for (size_t x = 0; x < input.at(0).size(); x++) {
    if (ColumnIsEmpty(input, x)) {
      for (auto& row : input) {
        row.insert(row.begin() + x, row.at(x));
      }
      x++;
    }
  }
}

std::vector<std::pair<Galaxy*, Galaxy*>>
GetPairs(const std::vector<Galaxy>& galaxies) {
  std::vector<std::pair<Galaxy*, Galaxy*>> pairs;
  for (size_t i = 0; i < galaxies.size(); ++i) {
    for (size_t j = i + 1; j < galaxies.size(); ++j) {
      pairs.emplace_back(&galaxies[i], &galaxies[j]);
    }
  }
  return pairs;
}
