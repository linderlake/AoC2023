#include "symbol_processing.h"
namespace {

bool CharacterIsASymbol(const char c) {
  return c != '.' && !CharacterIsADigit(c);
}

bool NumberIsAdjacentToASymbolHorizontally(const std::string& row,
                                           const std::string_view& fullNumber,
                                           const size_t rowIndex) {
  // Horizontal left
  if (rowIndex > 0 && CharacterIsASymbol(row[rowIndex - 1])) {
    return true;
  }
  // Horizontal right
  if ((rowIndex + fullNumber.size()) < row.size() &&
      CharacterIsASymbol(row[rowIndex + fullNumber.size()])) {
    return true;
  }
  return false;
}

bool NumberIsAdjacentToASymbolVertically(const std::string& row,
                                         const std::string_view& fullNumber,
                                         const size_t rowIndex) {
  for (size_t i = 0; i < fullNumber.size(); i++) {
    if (CharacterIsASymbol(row[rowIndex + i])) {
      return true;
    }
  }
  return false;
}

void FindAdjacentNumbersInRow(const std::string& row, const size_t rowIndex,
                              std::vector<AdjacentNumber>& adjacentNumbers,
                              const int yOffset) {
  bool digitFoundInPrevPos{false};
  // +1x
  if (row.size() > rowIndex + 1 && CharacterIsADigit(row[rowIndex + 1])) {
    adjacentNumbers.push_back(AdjacentNumber{1, yOffset});
    digitFoundInPrevPos = true;
  }
  // +0x (below or above gear)
  if (not digitFoundInPrevPos && CharacterIsADigit(row[rowIndex])) {
    adjacentNumbers.push_back(AdjacentNumber{0, yOffset});
    digitFoundInPrevPos = true;
  } else if (!CharacterIsADigit(row[rowIndex])) {
    digitFoundInPrevPos = false;
  }
  // -1x
  if (not digitFoundInPrevPos && rowIndex > 0 &&
      CharacterIsADigit(row[rowIndex - 1])) {
    adjacentNumbers.push_back(AdjacentNumber{-1, yOffset});
  }
}
size_t FindStartingCharIndex(const std::string& row, const size_t charIndex) {
  size_t i = charIndex;
  while (i > 0 && CharacterIsADigit(row[i - 1])) {
    i--;
  }
  return i;
}
} // namespace

bool CharacterIsADigit(const char c) { return c >= '0' && c <= '9'; };
bool CharacterIsAGear(const char c) { return c == '*'; };

bool NumberIsAdjacentToASymbol(const std::optional<std::string>& prevRow,
                               const std::string& row,
                               const std::optional<std::string>& nextRow,
                               const std::string_view& fullNumber,
                               const size_t rowIndex) {
  if (NumberIsAdjacentToASymbolHorizontally(row, fullNumber, rowIndex) ||
      (prevRow.has_value() && (NumberIsAdjacentToASymbolHorizontally(
                                   prevRow.value(), fullNumber, rowIndex) ||
                               NumberIsAdjacentToASymbolVertically(
                                   prevRow.value(), fullNumber, rowIndex))) ||
      (nextRow.has_value() && (NumberIsAdjacentToASymbolHorizontally(
                                   nextRow.value(), fullNumber, rowIndex) ||
                               NumberIsAdjacentToASymbolVertically(
                                   nextRow.value(), fullNumber, rowIndex)))) {
    return true;
  }
  return false;
};

std::vector<AdjacentNumber> FindAdjacentNumbersToGear(
    const std::optional<std::string>& prevRow, const std::string& row,
    const std::optional<std::string>& nextRow, const size_t rowIndex) {
  std::vector<AdjacentNumber> adjacentNumbers;
  if (row.size() > rowIndex + 1 && CharacterIsADigit(row[rowIndex + 1])) {
    adjacentNumbers.emplace_back(AdjacentNumber{1, 0});
  }
  if (rowIndex > 0 && CharacterIsADigit(row[rowIndex - 1])) {
    adjacentNumbers.emplace_back(AdjacentNumber{-1, 0});
  }
  if (nextRow.has_value()) {
    FindAdjacentNumbersInRow(nextRow.value(), rowIndex, adjacentNumbers, 1);
  }
  if (prevRow.has_value()) {
    FindAdjacentNumbersInRow(prevRow.value(), rowIndex, adjacentNumbers, -1);
  }
  return adjacentNumbers;
}

int GetAdjacentNumbersAndCalculateGearRatio(
    const std::vector<AdjacentNumber>& adjacentNumbers,
    const std::optional<std::string>& prevRow, const std::string& row,
    const std::optional<std::string>& nextRow, const size_t rowIndex) {
  int answer{1};
  for (auto adjacentNumber : adjacentNumbers) {
    int y = adjacentNumber.offsetY;
    std::string selectedRow = y == 1   ? nextRow.value()
                              : y == 0 ? row
                                       : prevRow.value();
    answer *= std::stoi(std::string(GetFullNumber(
        selectedRow, FindStartingCharIndex(
                         selectedRow, rowIndex + adjacentNumber.offsetX))));
  }
  return answer;
};

std::string_view GetFullNumber(const std::string& row, const size_t charIndex) {
  size_t i = charIndex;
  while (i < row.size() && CharacterIsADigit(row[i])) {
    i++;
  }
  return std::string_view(row.data() + charIndex, i - charIndex);
};
