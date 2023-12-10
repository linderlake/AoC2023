#pragma once
#include <string>
#include <vector>

struct Seed {
  double sourceRangeStart;
  double rangeLength;
};

struct MapEntry {
  double sourceRangeStart;
  double destinationRangeStart;
  double rangeLength;
};

double CalculateLowestLocation(const std::vector<std::string>& input,
                               const std::vector<double>& seeds);

double ReverseLowestLocationSearch(const std::vector<std::string>& input,
                                   const std::vector<Seed>& seeds);
