#include "solutions.h"
#include "node.h"
#include <algorithm>
#include <deque>
#include <numeric>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  auto& instructions{input.at(0)};
  std::deque<Node> network{CreateNetwork(input)};
  std::vector<Node*> currentNodes{SetupNeighbours(network, input, "AAA")};

  Node* currentNode{currentNodes.at(0)};
  while (true) {
    const auto instruction{instructions.at(answer % instructions.size())};

    answer++;
    instruction == 'L' ? currentNode = currentNode->leftNeighbour
                       : currentNode = currentNode->rightNeighbour;
    if (currentNode->name == "ZZZ") {
      break;
    }
  }
  return answer;
}

long long PartTwo(const std::vector<std::string>& input) {
  long long answer{};
  auto& instructions{input.at(0)};
  std::deque<Node> network{CreateNetwork(input)};
  std::vector<Node*> currentNodes{SetupNeighbours(network, input, "A")};

  std::vector<long long> answers;
  while (currentNodes.size() > 0) {
    const auto instruction{instructions.at(answer % instructions.size())};
    answer++;
    for (auto& node : currentNodes) {
      instruction == 'L' ? node = node->leftNeighbour
                         : node = node->rightNeighbour;
    }
    auto it = std::remove_if(
        currentNodes.begin(), currentNodes.end(),
        [](const Node* node) { return node->name.ends_with("Z"); });
    if (it != currentNodes.end()) {
      currentNodes.erase(it, currentNodes.end());
      answers.push_back(answer);
    }
  }
  long long lcm{answers.at(0)};
  for (size_t i = 1; i < answers.size(); ++i) {
    lcm = std::lcm(lcm, answers.at(i));
  }
  return lcm;
}
