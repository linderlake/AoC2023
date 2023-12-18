#include "placeholder.h"

bool RowIsEmpty(const std::vector<std::string>& input, size_t y) {
  return (std::all_of(input.at(y).begin(), input.at(y).end(),
                      [](auto c) { return c == '.'; }));
}
bool ColumnIsEmpty(const std::vector<std::string>& input, size_t x) {
  return (std::all_of(input.begin(), input.end(),
                      [x](auto row) { return row.at(x) == '.'; }));
}