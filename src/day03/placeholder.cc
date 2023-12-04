#include "placeholder.h"
namespace {
bool CharacterIsASymbol(const char c) { return c != '.'; }
bool NumberIsAdjacentToASymbolHorizontally(const std::string& row,
                                           const std::string& fullNumber,
                                           const size_t rowIndex) {
  // Horizontal left
  if (rowIndex > 0 && CharacterIsASymbol(row[rowIndex - 1])) {
    return true;
  }
  // Horizontal right
  if ((rowIndex + fullNumber.size()) <= row.size() &&
      CharacterIsASymbol(row[rowIndex + fullNumber.size()])) {
    return true;
  }
  return false;
}
bool NumberIsAdjacentToASymbolVertically(const std::string& row,
                                         const std::string& fullNumber,
                                         const size_t rowIndex) {
  for (size_t i = 0; i < fullNumber.size(); i++) {
    if (CharacterIsASymbol(row[rowIndex + i])) {
      return true;
    }
  }
  return false;
}
} // namespace
bool CharacterIsADigit(const char c) { return c >= '0' && c <= '9'; };

bool NumberIsAdjacentToASymbol(const std::optional<std::string>& prevRow,
                               const std::string& row,
                               const std::optional<std::string>& nextRow,
                               const std::string& fullNumber,
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

std::string GetFullNumber(const std::string& row, const size_t rowIndex) {
  std::string number;
  for (size_t i = rowIndex; i < row.size(); i++) {
    if (!CharacterIsADigit(row[i])) {
      break;
    }
    number += row[i];
  }
  return number;
};