#pragma once
#include <optional>
#include <string>
#include <vector>

struct AdjacentNumber {
  int offsetX;
  int offsetY;
  AdjacentNumber(int x, int y) : offsetX(x), offsetY(y) {}
};

bool CharacterIsADigit(const char c);
bool CharacterIsAGear(const char c);
bool NumberIsAdjacentToASymbol(const std::optional<std::string>& prevRow,
                               const std::string& row,
                               const std::optional<std::string>& nextRow,
                               const std::string_view& fullNumber,
                               const size_t rowIndex);
std::vector<AdjacentNumber> FindAdjacentNumbersToGear(
    const std::optional<std::string>& prevRow, const std::string& row,
    const std::optional<std::string>& nextRow, const size_t rowIndex);
std::string_view GetFullNumber(const std::string& row, const size_t rowIndex);
int GetAdjacentNumbersAndCalculateGearRatio(
    const std::vector<AdjacentNumber>& adjacentNumbers,
    const std::optional<std::string>& prevRow, const std::string& row,
    const std::optional<std::string>& nextRow, const size_t rowIndex);