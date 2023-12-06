#include "AoCHelper.h"
#include "solutions.h"
#include <iostream>

int main() {
  std::vector<std::string> exampleInput{};
  AoCHelper aocHelper{"2023", "4"};
  auto result = aocHelper.get_input();

  std::cout << "Puzzle one: " << PartOne(result) << std::endl;
  std::cout << "Puzzle two: " << PartTwo(result) << std::endl;
}
