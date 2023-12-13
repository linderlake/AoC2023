#pragma once
#include <queue>
#include <vector>

struct Tile {
  char symbol;
  std::vector<Tile*> connections;
  bool visited = false;
  bool start = false;
  bool visitable = true;
  Tile(char symbol);
};

void AddConnectionNorth(Tile& tile, size_t x, size_t y,
                        std::vector<std::vector<Tile>>& tiles);
void AddConnectionSouth(Tile& tile, size_t x, size_t y,
                        std::vector<std::vector<Tile>>& tiles);
void AddConnectionWest(Tile& tile, size_t x, std::vector<Tile>& tileRow);
void AddConnectionEast(Tile& tile, size_t x, std::vector<Tile>& tileRow);

int BFS(std::queue<Tile*>& q);
int FindLoop(std::queue<Tile*>& q);
