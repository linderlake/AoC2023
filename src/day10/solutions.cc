#include "solutions.h"
#include "placeholder.h"
#include <queue>
#include <vector>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  std::vector<std::vector<Tile>> tiles;
  tiles.reserve(input.size());
  for (size_t i = 0; i < input.size(); i++) {
    const auto& row{input.at(i)};
    std::vector<Tile> tileRow;
    tileRow.reserve(row.size());
    for (const auto& c : row) {
      tileRow.emplace_back(Tile{c});
    }
    tiles.push_back(tileRow);
  }
  Tile* start;
  for (size_t y = 0; y < tiles.size(); y++) {
    auto& tileRow = tiles.at(y);
    for (size_t x = 0; x < tileRow.size(); x++) {
      auto& tile{tileRow.at(x)};
      switch (tile.symbol) {
      case '|':
        if (y != 0) {
          AddConnectionNorth(tile, x, y, tiles);
        }
        if (y != tiles.size() - 1) {
          AddConnectionSouth(tile, x, y, tiles);
        }
        break;
      case '-':
        if (x != 0) {
          AddConnectionWest(tile, x, tileRow);
        }
        if (x != tileRow.size() - 1) {
          AddConnectionEast(tile, x, tileRow);
        }
        break;
      case 'L':
        if (y != 0) {
          AddConnectionNorth(tile, x, y, tiles);
        }
        if (x != tileRow.size() - 1) {
          AddConnectionEast(tile, x, tileRow);
        }
        break;
      case 'J':
        if (x != 0) {
          AddConnectionWest(tile, x, tileRow);
        }
        if (y != 0) {
          AddConnectionNorth(tile, x, y, tiles);
        }
        break;
      case '7':
        if (y != tiles.size() - 1) {
          AddConnectionSouth(tile, x, y, tiles);
        }
        if (x != 0) {
          AddConnectionWest(tile, x, tileRow);
        }
        break;
      case 'F':
        if (y != tiles.size() - 1) {
          AddConnectionSouth(tile, x, y, tiles);
        }
        if (x != tileRow.size() - 1) {
          AddConnectionEast(tile, x, tileRow);
        }
        break;
      case '.':
        tile.visitable = false;
        break;
      case 'S':
        tile.start = true;
        start = &tile;
        if (y != 0) {
          AddConnectionNorth(tile, x, y, tiles);
        }
        if (y != tiles.size() - 1) {
          AddConnectionSouth(tile, x, y, tiles);
        }
        if (x != 0) {
          AddConnectionWest(tile, x, tileRow);
        }
        if (x != tileRow.size() - 1) {
          AddConnectionEast(tile, x, tileRow);
        }
        break;
      }
    }
  }
  std::vector<Tile*> loop;
  std::queue<Tile*> q;
  q.push(&*start);
  answer = FindLoop(q);

  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    if (row == "hej") {
      return 0;
    }
  }
  return answer;
}
