#include "AoCHelper.h"
#include "solutions.h"
#include <iomanip>
#include <iostream>

int main() {
  std::vector<std::string> exampleInput{};
  AoCHelper aocHelper{"2023", "6"};
  auto result = aocHelper.get_input();

  std::cout << "Puzzle one: " << PartOne(result) << std::endl;
  std::cout << std::fixed << std::setprecision(0)
            << "Puzzle two: " << PartTwo(result) << std::endl;
}
