#include "node.h"
#include <deque>

Node::Node(const std::string& name) : name(name){};
bool Node::operator==(const Node& rhs) const { return name == rhs.name; }

std::deque<Node> CreateNetwork(const std::vector<std::string>& input) {
  std::deque<Node> network;
  for (size_t i = 2; i < input.size(); ++i) {
    network.emplace_back(Node{input[i].substr(0, 3)});
  }
  return network;
}

std::vector<Node*> SetupNeighbours(std::deque<Node>& network,
                                   const std::vector<std::string>& input,
                                   const std::string& startNodes) {
  std::vector<Node*> currentNodes;
  // setup neighbours
  for (size_t i = 2; i < input.size(); ++i) {
    network.at(i - 2).leftNeighbour = &*std::find(
        network.begin(), network.end(), Node{input[i].substr(7, 3)});
    network.at(i - 2).rightNeighbour = &*std::find(
        network.begin(), network.end(), Node{input[i].substr(12, 3)});
    if (network.at(i - 2).name.ends_with(startNodes)) {
      currentNodes.push_back(&network.at(i - 2));
    }
  }
  return currentNodes;
}