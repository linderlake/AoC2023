#include "solutions.h"
#include "digit_handler.h"

const bool kREVERSE{true};
const bool kSTRINGSEARCH{true};

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    char firstNumber{FindNumber(row)};
    char lastNumber{FindNumber(row, kREVERSE)};
    answer += std::stoi(std::string{firstNumber, lastNumber});
  }
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    char firstNumber{FindNumber(row, !kREVERSE, kSTRINGSEARCH)};
    char lastNumber{FindNumber(row, kREVERSE, kSTRINGSEARCH)};
    answer += std::stoi(std::string{firstNumber, lastNumber});
  }
  return answer;
}