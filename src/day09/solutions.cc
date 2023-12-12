#include "solutions.h"
#include "helper_functions.h"
#include "sequence_extrapolation.h"
#include <algorithm>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    const auto rawSequence{myLib::split(row, ' ')};
    std::vector<int> numberSequence;
    numberSequence.reserve(rawSequence.size());
    std::transform(rawSequence.begin(), rawSequence.end(),
                   std::back_inserter(numberSequence),
                   [](auto s) { return std::stoi(s); });
    answer += ExtrapolateValues(numberSequence);
  }
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    const auto rawSequence{myLib::split(row, ' ')};
    std::vector<int> numberSequence;
    numberSequence.reserve(rawSequence.size());
    std::transform(rawSequence.begin(), rawSequence.end(),
                   std::back_inserter(numberSequence),
                   [](auto s) { return std::stoi(s); });
    std::reverse(numberSequence.begin(), numberSequence.end());
    answer += ExtrapolateValues(numberSequence);
  }
  return answer;
}
