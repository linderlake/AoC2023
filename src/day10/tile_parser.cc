#include "tile_parser.h"
#include <iostream>
#include <unordered_map>
#include <unordered_set>

Tile::Tile(char symbol, int x, int y) : symbol(symbol), x(x), y(y){};

namespace {

void AddConnectionNorth(
    Tile& tile, size_t x, size_t y,
    std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  if (y != 0) {
    tile.connections.emplace_back(&tiles->at(y - 1).at(x));
  }
}
void AddConnectionSouth(
    Tile& tile, size_t x, size_t y,
    std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  if (y != tiles->size() - 1) {
    tile.connections.emplace_back(&tiles->at(y + 1).at(x));
  }
};
void AddConnectionWest(Tile& tile, size_t x, std::vector<Tile>& tileRow) {
  if (x != 0) {
    tile.connections.emplace_back(&tileRow.at(x - 1));
  }
};
void AddConnectionEast(Tile& tile, size_t x, std::vector<Tile>& tileRow) {
  if (x != tileRow.size() - 1) {
    tile.connections.emplace_back(&tileRow.at(x + 1));
  }
};

int BFS(std::queue<Tile*>& q, std::unordered_map<Tile*, int>& distances,
        Tile*& finalTile) {
  auto& tile{q.front()};
  q.pop();
  tile->visited = true;

  // finished logic
  if (tile->connections.size() == 2 &&
      std::all_of(tile->connections.begin(), tile->connections.end(),
                  [](auto t) { return t->visited; })) {
    finalTile = tile;
    return distances[tile];
  }
  for (auto* connectedTile : tile->connections) {
    if (!connectedTile->visited && connectedTile->visitable &&
        std::any_of(connectedTile->connections.begin(),
                    connectedTile->connections.end(),
                    [&](auto& connection) { return connection == tile; })) {
      distances[connectedTile] = distances[tile] + 1;
      q.push(connectedTile);
    }
  }
  return 0;
};

Tile& ParseTileConnections(
    std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  Tile* start;
  for (size_t y = 0; y < tiles->size(); y++) {
    auto& tileRow = tiles->at(y);
    for (size_t x = 0; x < tileRow.size(); x++) {
      auto& tile{tileRow.at(x)};
      switch (tile.symbol) {
      case '|':
        AddConnectionNorth(tile, x, y, tiles);
        AddConnectionSouth(tile, x, y, tiles);
        break;
      case '-':
        AddConnectionWest(tile, x, tileRow);
        AddConnectionEast(tile, x, tileRow);
        break;
      case 'L':
        AddConnectionNorth(tile, x, y, tiles);
        AddConnectionEast(tile, x, tileRow);
        break;
      case 'J':
        AddConnectionWest(tile, x, tileRow);
        AddConnectionNorth(tile, x, y, tiles);
        break;
      case '7':
        AddConnectionSouth(tile, x, y, tiles);
        AddConnectionWest(tile, x, tileRow);
        break;
      case 'F':
        AddConnectionSouth(tile, x, y, tiles);
        AddConnectionEast(tile, x, tileRow);
        break;
      case '.':
        tile.visitable = false;
        break;
      case 'S':
        tile.start = true;
        start = &tile;
        AddConnectionNorth(tile, x, y, tiles);
        AddConnectionSouth(tile, x, y, tiles);
        AddConnectionWest(tile, x, tileRow);
        AddConnectionEast(tile, x, tileRow);
        break;
      }
    }
  }
  return *start;
}

bool TileIsInsideLoop(Tile* startTile,
                      std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  int wallCount{0};
  std::unordered_set<char> walls{'|', '7', 'F'};

  for (int x = 0; x <= startTile->x; ++x) {
    if ((*tiles)[startTile->y][x].visited &&
        walls.contains((*tiles)[startTile->y][x].symbol)) {
      ++wallCount;
    }
  }
  return wallCount % 2 != 0;
}

void FloodFill(Tile* startTile,
               std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  if (startTile->visited || startTile->filled) {
    return;
  }
  startTile->filled = true;

  std::vector<std::pair<int, int>> directions = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  for (const auto& direction : directions) {
    int newX = startTile->x + direction.first;
    int newY = startTile->y + direction.second;

    if (newX >= 0 && newX < static_cast<int>((*tiles)[0].size()) && newY >= 0 &&
        newY < static_cast<int>((*tiles).size()) &&
        !(*tiles)[newY][newX].visited) {
      FloodFill(&(*tiles)[newY][newX], tiles);
    }
  }
}
void Print2DMap(std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  for (auto& row : *tiles) {
    for (auto& tile : row) {
      if (tile.start) {
        std::cout << "\033[34m" << tile.symbol << "\033[0m";
        continue;
      }
      if (tile.visited) {
        std::cout << "\033[32m" << tile.symbol << "\033[0m";
        continue;
      }
      if (tile.enclosed) {
        std::cout << "\033[31m" << 'X' << "\033[0m";
        continue;
      }
      std::cout << tile.symbol;
    }
    std::cout << std::endl;
  }
}
} // namespace

Tile& ParseTiles(const std::vector<std::string>& input,
                 std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  for (size_t y = 0; y < input.size(); y++) {
    const auto& row{input.at(y)};
    std::vector<Tile> tileRow;
    tileRow.reserve(row.size());
    for (size_t x = 0; x < row.size(); x++) {
      tileRow.emplace_back(
          Tile{row.at(x), static_cast<int>(x), static_cast<int>(y)});
    }
    tiles->push_back(std::move(tileRow));
  }
  return ParseTileConnections(tiles);
}

int FindLoop(std::queue<Tile*>& q,
             std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  std::unordered_map<Tile*, int> distances;
  distances[q.front()] = 0;
  int loopDistance{0};
  Tile* finalTile;
  while (!q.empty() && loopDistance == 0) {
    loopDistance = BFS(q, distances, finalTile);
  }

  for (auto& row : *tiles) {
    for (auto& tile : row) {
      tile.visited = false;
    }
  }

  finalTile->visited = true;
  for (auto& connection : finalTile->connections) {
    auto* currTile = connection;
    while (currTile->symbol != 'S') {
      currTile->visited = true;
      for (auto& nextConnection : currTile->connections) {
        if (!nextConnection->visited) {
          currTile = nextConnection;
        }
      }
    }
  }
  return loopDistance;
};

int FindEnclosedAreas(std::unique_ptr<std::vector<std::vector<Tile>>>& tiles) {
  int count = 0;
  FloodFill(&tiles->at(0).at(0), tiles);

  for (auto& row : *tiles) {
    for (auto& tile : row) {
      if (!tile.start && !tile.visited && !tile.filled &&
          TileIsInsideLoop(&tile, tiles)) {
        tile.enclosed = true;
        count++;
      }
    }
  }
  Print2DMap(tiles);
  return count;
}
