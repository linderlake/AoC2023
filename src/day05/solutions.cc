#include "solutions.h"
#include "helper_functions.h"
#include "map_parser.h"
#include <algorithm>
#include <cassert>
#include <iterator>

double PartOne(const std::vector<std::string>& input) {
  auto seedsStrs{myLib::split(myLib::split(input.at(0), ':').at(1), ' ')};
  std::vector<double> seeds{};
  std::transform(seedsStrs.begin(), seedsStrs.end(), std::back_inserter(seeds),
                 [](auto& seed) { return std::stod(seed); });
  return CalculateLowestLocation(input, seeds);
}

double PartTwo(const std::vector<std::string>& input) {
  auto seedsStrs{myLib::split(myLib::split(input.at(0), ':').at(1), ' ')};
  std::vector<Seed> seeds{};
  assert(seedsStrs.size() % 2 == 0);
  for (size_t i = 0; i < seedsStrs.size(); i += 2) {
    Seed newSeed;
    newSeed.sourceRangeStart = std::stod(seedsStrs.at(i));
    newSeed.rangeLength = std::stod(seedsStrs.at(i + 1));
    seeds.push_back(newSeed);
  }
  return ReverseLowestLocationSearch(input, seeds);
}
