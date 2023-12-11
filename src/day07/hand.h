#pragma once
#include <string>
#include <unordered_map>
#include <vector>

enum class HandType {
  HighCard,
  OnePair,
  TwoPair,
  ThreeOfAKind,
  FullHouse,
  FourOfAKind,
  FiveOfAKind
};

struct Hand {
  std::string hand;
  int bid;
  HandType handType;
  std::vector<int> cardValues;
  Hand(const std::string& hand, int bid, const bool joker = false);

  double Strength();
  bool operator<(const Hand& rhs);

private:
  void DetermineHandType(const std::unordered_map<int, int>& cards);
  void DetermineJokerHandType(const std::unordered_map<int, int>& cards);
};

std::vector<Hand> ParseInputIntoHands(const std::vector<std::string>& input,
                                      const bool joker = false);