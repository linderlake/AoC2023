#include "solutions.h"
#include "placeholder.h"
#include <iomanip>
#include <iostream>
#include <numeric>
#include <tuple>

int PartOne(std::vector<std::string> input) {
  int answer{};
  std::vector<Galaxy> galaxies;
  DuplicateEmptyRowsAndColumns(input);
  for (size_t y{0}; y < input.size(); y++) {
    const auto& row{input.at(y)};
    for (size_t x{0}; x < row.size(); x++) {
      if (row.at(x) == '#') {
        galaxies.emplace_back(Galaxy{static_cast<int>(x), static_cast<int>(y)});
      }
    }
  }

  auto pairs{GetPairs(galaxies)};
  for (const auto& pair : pairs) {
    const auto& [galaxy1, galaxy2] = pair;
    const auto x1{galaxy1->x};
    const auto y1{galaxy1->y};
    const auto x2{galaxy2->x};
    const auto y2{galaxy2->y};
    int x_diff{x2 - x1};
    int y_diff{y2 - y1};
    int x_step{0};
    int y_step{0};
    if (x_diff != 0) {
      x_step = x_diff / std::gcd(x_diff, y_diff);
    }
    if (y_diff != 0) {
      y_step = y_diff / std::gcd(x_diff, y_diff);
    }
    int x{x1};
    int y{y1};
    while (x != x2 || y != y2) {
      int prev_x = x;
      int prev_y = y;
      x += x_step;
      y += y_step;
      answer += std::abs((x - prev_x)) + std::abs((y - prev_y));
    }
  }
  return answer;
}

long PartTwo(std::vector<std::string> input, const int weight) {
  std::vector<Node> nodes;
  std::vector<Galaxy> galaxies;

  MarkEmptyRowsAndColumns(input);
  for (size_t y{0}; y < input.size(); y++) {
    const auto& row{input.at(y)};
    for (size_t x{0}; x < row.size(); x++) {
      if (row.at(x) == '#') {
        galaxies.emplace_back(Galaxy{static_cast<int>(x), static_cast<int>(y)});
        nodes.emplace_back(galaxies.back());
      } else if (row.at(x) == '-') {
        nodes.emplace_back(
            Node{static_cast<int>(x), static_cast<int>(y), weight});
      } else {
        nodes.emplace_back(Node{static_cast<int>(x), static_cast<int>(y), 1});
      }
    }
  }

  std::sort(nodes.begin(), nodes.end(), [](const Node& a, const Node& b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
  });

  std::vector<Galaxy*> galaxyPointers;
  for (auto& galaxy : galaxies) {
    galaxyPointers.push_back(&galaxy);
  }

  auto galaxyPairs{GetPairs(galaxyPointers)};
  long answer{};
  for (const auto& pair : galaxyPairs) {
    const auto& [galaxy1, galaxy2] = pair;
    const auto xStart{galaxy1->x};
    const auto yStart{galaxy1->y};
    const auto xEnd{galaxy2->x};
    const auto yEnd{galaxy2->y};
    int xDirection{xEnd - xStart};
    int yDirection{yEnd - yStart};
    int xStep{0};
    int yStep{0};
    if (xDirection != 0) {
      xStep = xDirection / std::abs(xDirection);
    }
    if (yDirection != 0) {
      yStep = yDirection / std::abs(yDirection);
    }
    int xCurrent{xStart};
    int yCurrent{yStart};
    std::vector<std::pair<int, int>> path;
    path.reserve(std::abs(xDirection) + std::abs(yDirection) + 1);
    while (xCurrent != xEnd) {
      xCurrent += xStep;
      path.push_back({xCurrent, yCurrent});
    }
    while (yCurrent != yEnd) {
      yCurrent += yStep;
      path.push_back({xCurrent, yCurrent});
    }
    for (const auto& position : path) {
      auto it = std::lower_bound(
          nodes.begin(), nodes.end(), Node{position.first, position.second, 0},
          [](const Node& a, const Node& b) {
            return std::tie(a.x, a.y) < std::tie(b.x, b.y);
          });
      if (it != nodes.end() && it->x == position.first &&
          it->y == position.second) {
        answer += it->weight;
      } else {
        answer++;
      }
    }
  }

  return answer;
}
