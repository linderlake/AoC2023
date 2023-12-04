#include "solutions.h"
#include "helper_functions.h"
#include <climits>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  for (auto row : input) {
    bool possibleCombination{true};
    auto splitRow{myLib::split(row, ':')};
    int gameId{std::stoi(myLib::split(splitRow[0], ' ')[1])};
    for (auto game : myLib::split(splitRow[1], ';')) {
      for (auto set : myLib::split(game, ',')) {
        set.erase(0, set.find_first_not_of(' '));
        auto cube{myLib::split(set, ' ')};
        auto numberOfCubes{std::stoi(cube[0])};
        auto cubeColor{cube[1]};
        if ((cubeColor == "red" && numberOfCubes > 12) ||
            (cubeColor == "green" && numberOfCubes > 13) ||
            (cubeColor == "blue" && numberOfCubes > 14)) {
          possibleCombination = false;
        }
      }
    }
    if (possibleCombination) {
      answer += gameId;
    }
  }
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  for (auto row : input) {
    int lowestAmountOfRedCubes{0};
    int lowestAmountOfGreenCubes{0};
    int lowestAmountOfBlueCubes{0};
    for (auto game : myLib::split(myLib::split(row, ':')[1], ';')) {
      for (auto set : myLib::split(game, ',')) {
        set.erase(0, set.find_first_not_of(' '));
        auto cube{myLib::split(set, ' ')};
        auto numberOfCubes{std::stoi(cube[0])};
        auto cubeColor{cube[1]};
        if (cubeColor == "red" && numberOfCubes > lowestAmountOfRedCubes) {
          lowestAmountOfRedCubes = numberOfCubes;
        } else if (cubeColor == "green" &&
                   numberOfCubes > lowestAmountOfGreenCubes) {
          lowestAmountOfGreenCubes = numberOfCubes;
        } else if (cubeColor == "blue" &&
                   numberOfCubes > lowestAmountOfBlueCubes) {
          lowestAmountOfBlueCubes = numberOfCubes;
        }
      }
    }
    answer += lowestAmountOfRedCubes * lowestAmountOfBlueCubes *
              lowestAmountOfGreenCubes;
  }
  return answer;
}
