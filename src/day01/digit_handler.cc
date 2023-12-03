#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, char> digitMap{
    {"one", '1'}, {"two", '2'},   {"three", '3'}, {"four", '4'}, {"five", '5'},
    {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}};

char* ContainsDigits(const std::string& nextFiveCharacters,
                     const bool reverse /* = false */) {
  try {
    std::string threeLetter;
    std::string fourLetter;
    std::string fiveLetter;

    int startIdxThree = reverse ? 2 : 0;
    int startIdxFour = reverse ? 1 : 0;
    int startIdxFive = reverse ? 0 : 0;

    threeLetter = nextFiveCharacters.substr(startIdxThree, 3);
    fourLetter = nextFiveCharacters.substr(startIdxFour, 4);
    fiveLetter = nextFiveCharacters.substr(startIdxFive, 5);
    if (digitMap.contains(threeLetter)) {
      return &digitMap.find(threeLetter)->second;
    } else if (digitMap.contains(fourLetter)) {
      return &digitMap.find(fourLetter)->second;
    } else if (digitMap.contains(fiveLetter)) {
      return &digitMap.find(fiveLetter)->second;
    }
    return nullptr;
  } catch (const std::out_of_range& ex) {
    std::cerr << ex.what() << std::endl;
    return nullptr;
  }
}

char FindNumber(std::string row, const bool reverse /* = false */,
                const bool stringSearch /* = false */) {
  if (reverse) {
    std::ranges::reverse(row.begin(), row.end());
  };
  for (size_t i = 0; i < row.size(); ++i) {
    char c = row[i];
    if (c >= '0' && c <= '9') {
      return c;
    } else if (stringSearch) {
      auto readableChars{row.size() - i};
      std::string nextFiveCharacters{};
      std::string newRow{row};
      if (reverse) {
        std::ranges::reverse(
            newRow.begin(), newRow.end()); // undo previous reverse so the chars
                                           // can be read in correct order
        std::copy(newRow.end() - i - (readableChars < 5 ? readableChars : 5),
                  newRow.end() - i, std::back_inserter(nextFiveCharacters));
      } else {
        std::copy(newRow.begin() + i,
                  newRow.begin() + i + (readableChars < 5 ? readableChars : 5),
                  std::back_inserter(nextFiveCharacters));
      }
      char* foundDigit{};
      foundDigit = ContainsDigits(nextFiveCharacters, reverse);
      if (foundDigit != nullptr) {
        return *foundDigit;
      }
    }
  }
  std::cerr << "error: no number found in row:" << row << std::endl;
  return '0';
}
