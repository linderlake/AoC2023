#include "map_parser.h"
#include "helper_functions.h"
#include <algorithm>
#include <vector>

namespace {
void ParseMapEntries(std::vector<std::string>::const_iterator beginIt,
                     std::vector<std::string>::const_iterator endIt,
                     std::vector<MapEntry>& mapEntries,
                     const bool destinationRangeSort) {
  auto it = beginIt;
  while (it != endIt) {
    auto splitStr{myLib::split(*it, ' ')};
    MapEntry mapEntry;
    mapEntry.destinationRangeStart = std::stod(splitStr.at(0));
    mapEntry.sourceRangeStart = std::stod(splitStr.at(1));
    mapEntry.rangeLength = std::stod(splitStr.at(2));
    mapEntries.push_back(mapEntry);
    it++;
  }
  if (destinationRangeSort) {
    std::sort(mapEntries.begin(), mapEntries.end(), [](auto lhs, auto rhs) {
      return lhs.destinationRangeStart < rhs.destinationRangeStart;
    });
  } else {
    std::sort(mapEntries.begin(), mapEntries.end(), [](auto lhs, auto rhs) {
      return lhs.sourceRangeStart < rhs.sourceRangeStart;
    });
  }
}

void ParseSeedMapsIntoMaps(const std::vector<std::string>& input,
                           std::vector<MapEntry>& seedToSoilMap,
                           std::vector<MapEntry>& soilToFertilizerMap,
                           std::vector<MapEntry>& fertilizerToWaterMap,
                           std::vector<MapEntry>& waterToLightMap,
                           std::vector<MapEntry>& lightToTemperatureMap,
                           std::vector<MapEntry>& temperatureToHumidityMap,
                           std::vector<MapEntry>& humidityToLocationMap,
                           const bool destinationRangeSort = false) {

  auto seedToSoilIt =
      std::find(input.begin(), input.end(), "seed-to-soil map:");
  auto soilToFertilizerIt =
      std::find(input.begin(), input.end(), "soil-to-fertilizer map:");
  auto fertilizerToWaterIt =
      std::find(input.begin(), input.end(), "fertilizer-to-water map:");
  auto waterToLightIt =
      std::find(input.begin(), input.end(), "water-to-light map:");
  auto lightToTemperatureIt =
      std::find(input.begin(), input.end(), "light-to-temperature map:");
  auto temperatureToHumidityIt =
      std::find(input.begin(), input.end(), "temperature-to-humidity map:");
  auto humidityToLocationIt =
      std::find(input.begin(), input.end(), "humidity-to-location map:");

  // parse seeds
  ParseMapEntries(seedToSoilIt + 1, soilToFertilizerIt - 1, seedToSoilMap,
                  destinationRangeSort);
  ParseMapEntries(soilToFertilizerIt + 1, fertilizerToWaterIt - 1,
                  soilToFertilizerMap, destinationRangeSort);
  ParseMapEntries(fertilizerToWaterIt + 1, waterToLightIt - 1,
                  fertilizerToWaterMap, destinationRangeSort);
  ParseMapEntries(waterToLightIt + 1, lightToTemperatureIt - 1, waterToLightMap,
                  destinationRangeSort);
  ParseMapEntries(lightToTemperatureIt + 1, temperatureToHumidityIt - 1,
                  lightToTemperatureMap, destinationRangeSort);
  ParseMapEntries(temperatureToHumidityIt + 1, humidityToLocationIt - 1,
                  temperatureToHumidityMap, destinationRangeSort);
  ParseMapEntries(humidityToLocationIt + 1, input.end(), humidityToLocationMap,
                  destinationRangeSort);
}

double FindMapping(const std::vector<MapEntry>& mapEntries, double key) {
  size_t i{0};
  while (i < mapEntries.size()) {
    if (key < mapEntries.at(i).sourceRangeStart) {
      break;
    }
    i++;
  }
  i = i == 0 ? 0 : --i; // go to previous element
  auto diff = key - mapEntries.at(i).sourceRangeStart;
  if (diff >= 0 &&
      diff < mapEntries.at(i).rangeLength) { // key is within range, use mapping
    return mapEntries.at(i).destinationRangeStart + diff;
  }
  return key;
}

double FindReverseMapping(const std::vector<MapEntry>& mapEntries, double key) {
  size_t i{0};
  while (i < mapEntries.size()) {
    if (key < mapEntries.at(i).destinationRangeStart) {
      break;
    }
    i++;
  }
  i = i == 0 ? 0 : --i; // go to previous element
  auto diff = key - mapEntries.at(i).destinationRangeStart;
  if (diff >= 0 &&
      diff < mapEntries.at(i).rangeLength) { // key is within range, use mapping
    return mapEntries.at(i).sourceRangeStart + diff;
  }
  return key;
}

} // namespace

double CalculateLowestLocation(const std::vector<std::string>& input,
                               const std::vector<double>& seeds) {

  std::vector<MapEntry> seedToSoilMap{};
  std::vector<MapEntry> soilToFertilizerMap{};
  std::vector<MapEntry> fertilizerToWaterMap{};
  std::vector<MapEntry> waterToLightMap{};
  std::vector<MapEntry> lightToTemperatureMap{};
  std::vector<MapEntry> temperatureToHumidityMap{};
  std::vector<MapEntry> humidityToLocationMap{};
  ParseSeedMapsIntoMaps(input, seedToSoilMap, soilToFertilizerMap,
                        fertilizerToWaterMap, waterToLightMap,
                        lightToTemperatureMap, temperatureToHumidityMap,
                        humidityToLocationMap);

  double answer{std::numeric_limits<double>::max()};
  for (const auto& seed : seeds) {
    double current{FindMapping(seedToSoilMap, seed)};
    current = FindMapping(soilToFertilizerMap, current);
    current = FindMapping(fertilizerToWaterMap, current);
    current = FindMapping(waterToLightMap, current);
    current = FindMapping(lightToTemperatureMap, current);
    current = FindMapping(temperatureToHumidityMap, current);
    current = FindMapping(humidityToLocationMap, current);
    if (current < answer) {
      answer = current;
    }
  }
  return answer;
}

double ReverseLowestLocationSearch(const std::vector<std::string>& input,
                                   const std::vector<Seed>& seeds) {
  std::vector<MapEntry> seedToSoilMap{};
  std::vector<MapEntry> soilToFertilizerMap{};
  std::vector<MapEntry> fertilizerToWaterMap{};
  std::vector<MapEntry> waterToLightMap{};
  std::vector<MapEntry> lightToTemperatureMap{};
  std::vector<MapEntry> temperatureToHumidityMap{};
  std::vector<MapEntry> humidityToLocationMap{};
  ParseSeedMapsIntoMaps(input, seedToSoilMap, soilToFertilizerMap,
                        fertilizerToWaterMap, waterToLightMap,
                        lightToTemperatureMap, temperatureToHumidityMap,
                        humidityToLocationMap, true);
  double i{1};
  while (true) {
    auto current = FindReverseMapping(humidityToLocationMap, i);
    current = FindReverseMapping(temperatureToHumidityMap, current);
    current = FindReverseMapping(lightToTemperatureMap, current);
    current = FindReverseMapping(waterToLightMap, current);
    current = FindReverseMapping(fertilizerToWaterMap, current);
    current = FindReverseMapping(soilToFertilizerMap, current);
    current = FindReverseMapping(seedToSoilMap, current);

    auto it = std::find_if(seeds.begin(), seeds.end(), [&](auto seed) {
      auto diff = current - seed.sourceRangeStart;
      return diff >= 0 && diff <= seed.rangeLength;
    });
    if (it != seeds.end()) {
      return i;
    }
    i++;
  }
  return 0;
};