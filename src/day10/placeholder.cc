#include "placeholder.h"
#include <iostream>
#include <unordered_map>
Tile::Tile(char symbol) : symbol(symbol){};

void AddConnectionNorth(Tile& tile, size_t x, size_t y,
                        std::vector<std::vector<Tile>>& tiles) {
  tile.connections.emplace_back(&tiles.at(y - 1).at(x));
}
void AddConnectionSouth(Tile& tile, size_t x, size_t y,
                        std::vector<std::vector<Tile>>& tiles) {
  tile.connections.emplace_back(&tiles.at(y + 1).at(x));
};

void AddConnectionWest(Tile& tile, size_t x, std::vector<Tile>& tileRow) {
  tile.connections.emplace_back(&tileRow.at(x - 1));
};

void AddConnectionEast(Tile& tile, size_t x, std::vector<Tile>& tileRow) {
  tile.connections.emplace_back(&tileRow.at(x + 1));
};

int BFS(std::queue<Tile*>& q, std::unordered_map<Tile*, int>& distances) {
  auto tile{q.front()};
  q.pop();
  tile->visited = true;

  // finished logic
  if (tile->connections.size() == 2 &&
      std::all_of(tile->connections.begin(), tile->connections.end(),
                  [](auto t) { return t->visited; })) {
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

int FindLoop(std::queue<Tile*>& q) {
  std::unordered_map<Tile*, int> distances;
  distances[q.front()] = 0;
  int loopDistance{0};
  while (!q.empty() && loopDistance == 0) {
    loopDistance = BFS(q, distances);
  }
  return loopDistance;
};
