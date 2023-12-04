#include "solutions.h"
#include "placeholder.h"
#include <optional>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  for (size_t hIndex = 0; hIndex < input.size(); hIndex++) {
    auto row{input[hIndex]};
    int skips{0};
    for (size_t rowIndex = 0; rowIndex < row.size(); rowIndex++) {
      if (skips > 0) {
        skips--;
        continue;
      }
      char c{row[rowIndex]};
      if (CharacterIsADigit(c)) {
        auto fullNumber{GetFullNumber(row, rowIndex)};
        skips = fullNumber.length() - 1;
        std::optional<std::string> prevRow{};
        std::optional<std::string> nextRow{};
        if (hIndex > 0) {
          prevRow = input[hIndex - 1];
        }
        if (hIndex < (input.size() - 1)) {
          nextRow = input[hIndex + 1];
        }

        if (NumberIsAdjacentToASymbol(prevRow, row, nextRow, fullNumber,
                                      rowIndex)) {
          answer += std::stoi(fullNumber);
        }
      }
    }
  }
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  for (auto row : input) {
  }
  return answer;
}
