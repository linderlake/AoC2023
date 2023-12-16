#pragma once
#include <memory>
#include <queue>
#include <string>
#include <vector>

struct Tile {
  char symbol;
  int x;
  int y;
  std::vector<Tile*> connections;
  bool visited = false;
  bool start = false;
  bool visitable = true;
  bool filled = false;
  bool enclosed = false;
  Tile(char symbol, int x, int y);
};

Tile& ParseTiles(const std::vector<std::string>& input,
                 std::unique_ptr<std::vector<std::vector<Tile>>>& tiles);
int FindLoop(std::queue<Tile*>& q,
             std::unique_ptr<std::vector<std::vector<Tile>>>& tiles);
int FindEnclosedAreas(std::unique_ptr<std::vector<std::vector<Tile>>>& tiles);