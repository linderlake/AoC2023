#include "placeholder.h"

bool CharacterIsADigit(const char c) { return c >= '0' && c <= '9'; };
int GetNumber(const std::string& row) { return std::stoi(row); };
