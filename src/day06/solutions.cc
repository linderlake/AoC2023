#include "solutions.h"
#include "helper_functions.h"

int PartOne(const std::vector<std::string>& input) {
  int answer{1};
  auto times{myLib::split(input.at(0), ' ')};
  auto distances{myLib::split(input.at(1), ' ')};
  for (size_t i = 1; i < times.size(); i++) {
    auto time{std::stoi(times.at(i))};
    auto bestDistance{std::stoi(distances.at(i))};
    int recordBeats{0};
    for (int holdTime = 1; holdTime <= time; holdTime++) {
      if (bestDistance < holdTime * (time - holdTime)) {
        recordBeats++;
      };
    }
    answer *= recordBeats;
  }
  return answer;
}

double PartTwo(const std::vector<std::string>& input) {
  double answer{1};
  auto timevalues{myLib::split(input.at(0), ':').at(1)};
  timevalues.erase(
      std::remove_if(timevalues.begin(), timevalues.end(), ::isspace),
      timevalues.end());

  auto distanceValues{myLib::split(input.at(1), ':').at(1)};
  distanceValues.erase(
      std::remove_if(distanceValues.begin(), distanceValues.end(), ::isspace),
      distanceValues.end());

  auto time{std::stod(timevalues)};
  auto bestDistance{std::stod(distanceValues)};
  double recordBeats{0};
  for (double holdTime = 1; holdTime <= time; holdTime++) {
    if (bestDistance < holdTime * (time - holdTime)) {
      recordBeats++;
    };
  }
  answer *= recordBeats;

  return answer;
}
