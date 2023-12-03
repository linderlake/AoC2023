#include "AoCHelper.h"
#include "solutions.h"
#include <iostream>

int main() {
  std::vector<std::string> exampleInput{
      "two1nine",         "eightwothree", "abcone2threexyz", "xtwone3four",
      "4nineeightseven2", "zoneight234",  "7pqrstsixteen"};
  AoCHelper a1{"2023", "1"};
  auto result = a1.get_input();

  std::cout << "Puzzle one: " << PartOne(result) << std::endl;
  std::cout << "Puzzle two: " << PartTwo(result) << std::endl;
}