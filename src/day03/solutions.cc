#include "solutions.h"
#include "symbol_processing.h"
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

        const std::optional<std::string>& prevRow =
            rowIndex > 0 ? std::make_optional(input[rowIndex - 1])
                         : std::nullopt;
        const std::optional<std::string>& nextRow =
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
  for (size_t rowIndex = 0; rowIndex < input.size(); rowIndex++) {
    const auto& row{input[rowIndex]};
    for (size_t charIndex = 0; charIndex < row.size(); charIndex++) {

      // find gears
      char c{row[charIndex]};
      if (not CharacterIsAGear(c)) {
        continue;
      }

      // perform a search in the vicinity of the gear
      const std::optional<std::string>& prevRow =
          rowIndex > 0 ? std::make_optional(input[rowIndex - 1]) : std::nullopt;
      const std::optional<std::string>& nextRow =
          rowIndex < (input.size() - 1)
              ? std::make_optional(input[rowIndex + 1])
              : std::nullopt;
      auto adjacentNumbers{
          FindAdjacentNumbersToGear(prevRow, row, nextRow, charIndex)};
      if (adjacentNumbers.size() != 2 || adjacentNumbers.empty()) {
        continue;
      }

      // get full numbers, multiply them and add to answer
      answer += GetAdjacentNumbersAndCalculateGearRatio(
          adjacentNumbers, prevRow, row, nextRow, charIndex);
    }
  }
  return answer;
}
