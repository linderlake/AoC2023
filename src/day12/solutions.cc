#include "solutions.h"
#include "helper_functions.h"
#include "placeholder.h"
#include <algorithm>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    const auto& splitRow{myLib::split(row, ' ')};
    const auto& recordStr{splitRow.at(0)};
    const auto& rangeStr{myLib::split(splitRow.at(1), ',')};

    std::vector<int> range;
    range.reserve(rangeStr.size() / 2);
    std::transform(rangeStr.begin(), rangeStr.end(), range.begin(),
                   [](const auto& c) { return std::stoi(c); });
  }
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    if (row == "hej")
      answer++;
  }
  return answer;
}
