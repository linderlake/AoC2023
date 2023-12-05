#pragma once
#include <optional>
#include <string>
bool CharacterIsADigit(const char c);
bool NumberIsAdjacentToASymbol(const std::optional<std::string>& prevRow,
                               const std::string& row,
                               const std::optional<std::string>& nextRow,
                               const std::string_view& fullNumber,
                               const size_t rowIndex);
std::string_view GetFullNumber(const std::string& row, const size_t rowIndex);