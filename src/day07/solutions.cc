#include "solutions.h"
#include "hand.h"
#include <algorithm>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  std::vector<Hand> hands{ParseInputIntoHands(input)};
  std::sort(hands.begin(), hands.end());

  for (size_t i = 1; i <= hands.size(); i++) {
    answer += hands.at(i - 1).bid * i;
  }
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  const bool jokers{true};
  std::vector<Hand> hands{ParseInputIntoHands(input, jokers)};
  std::sort(hands.begin(), hands.end());

  for (size_t i = 1; i <= hands.size(); i++) {
    answer += hands.at(i - 1).bid * i;
  }
  return answer;
}
