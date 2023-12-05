#include "solutions.h"
#include "number_cruncher.h"
#include <optional>

int PartOne(const std::vector<std::string>& input) {
  int answer{0};
  for (size_t rowIndex = 0; rowIndex < input.size(); rowIndex++) {
    const auto& row{input[rowIndex]};
    int skipCount{0};
    for (size_t charIndex = 0; charIndex < row.size(); charIndex++) {
      if (skipCount > 0) {
        skipCount--;
        continue;
      }
      char c{row[charIndex]};
      if (CharacterIsADigit(c)) {
        auto fullNumber{GetFullNumber(row, charIndex)};
        skipCount = fullNumber.length() - 1;

        std::optional<std::string> prevRow =
            rowIndex > 0 ? std::make_optional(input[rowIndex - 1])
                         : std::nullopt;
        std::optional<std::string> nextRow =
            rowIndex < (input.size() - 1)
                ? std::make_optional(input[rowIndex + 1])
                : std::nullopt;

        if (NumberIsAdjacentToASymbol(prevRow, row, nextRow, fullNumber,
                                      charIndex)) {
          answer += std::stoi(std::string(fullNumber));
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
