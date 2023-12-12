#pragma once
#include <deque>
#include <string>
#include <vector>

struct Node {
  std::string name;
  Node* leftNeighbour;
  Node* rightNeighbour;

  Node(const std::string& name);

  bool operator==(const Node& rhs) const;
};

std::deque<Node> CreateNetwork(const std::vector<std::string>& input);
std::vector<Node*> SetupNeighbours(std::deque<Node>& network,
                                   const std::vector<std::string>& input,
                                   const std::string& startNodes);