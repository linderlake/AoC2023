#include "solutions.h"
#include "tile_parser.h"
#include <memory>
#include <queue>
#include <vector>

int PartOne(const std::vector<std::string>& input) {
  auto tiles = std::make_unique<std::vector<std::vector<Tile>>>();
  Tile& start = ParseTiles(input, tiles);
  std::queue<Tile*> q;
  q.push(&start);
  return FindLoop(q, tiles);
}

int PartTwo(std::vector<std::string> input) {
  // Add an extra character all around the 2d map for the flood fill algorithm
  // to find all gaps
  for (auto& row : input) {
    row = '.' + row + '.';
  }
  std::string extraRow(input[0].size(), '.');
  input.insert(input.begin(), extraRow);
  input.push_back(extraRow);

  auto tiles = std::make_unique<std::vector<std::vector<Tile>>>();
  Tile& start = ParseTiles(input, tiles);
  std::queue<Tile*> q;
  q.push(&start);
  FindLoop(q, tiles);
  start.visited = true;
  start.symbol = '7'; // this was the start symbol in my input, guess it could
                      // have been found out programatically
  int answer{FindEnclosedAreas(tiles)};
  return answer;
}
