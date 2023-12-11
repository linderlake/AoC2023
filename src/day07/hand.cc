#include "hand.h"
#include "helper_functions.h"
#include <unordered_map>

std::unordered_map<char, int> definedCardValuesWithoutJokers{
    {'A', 14}, {'K', 13}, {'Q', 12}, {'J', 11}, {'T', 10}, {'9', 9}, {'8', 8},
    {'7', 7},  {'6', 6},  {'5', 5},  {'4', 4},  {'3', 3},  {'2', 2}};

std::unordered_map<char, int> definedCardValuesWithJokers{
    {'A', 13}, {'K', 12}, {'Q', 11}, {'T', 10}, {'9', 9}, {'8', 8}, {'7', 7},
    {'6', 6},  {'5', 5},  {'4', 4},  {'3', 3},  {'2', 2}, {'J', 1}};

Hand::Hand(const std::string& hand, int bid, const bool joker)
    : hand(hand), bid(bid) {
  std::unordered_map<int, int> cards; // card, amount
  for (const auto c : hand) {
    int cardValue{joker ? definedCardValuesWithJokers.find(c)->second
                        : definedCardValuesWithoutJokers.find(c)->second};
    cards.insert_or_assign(cardValue, cards.contains(cardValue)
                                          ? ++cards.find(cardValue)->second
                                          : 1);
    cardValues.push_back(cardValue);
  }
  if (joker) {
    DetermineJokerHandType(cards);
  } else {
    DetermineHandType(cards);
  }
}

void Hand::DetermineHandType(const std::unordered_map<int, int>& cards) {
  switch (cards.size()) {
  case 5:
    handType = HandType::HighCard;
    break;
  case 4:
    handType = HandType::OnePair;
    break;
  case 3:
    if (std::any_of(cards.begin(), cards.end(),
                    [](const auto& card) { return card.second == 3; })) {
      handType = HandType::ThreeOfAKind;
    } else {
      handType = HandType::TwoPair;
    }
    break;
  case 2:
    if (std::any_of(cards.begin(), cards.end(),
                    [](const auto& card) { return card.second == 4; })) {
      handType = HandType::FourOfAKind;
    } else {
      handType = HandType::FullHouse;
    }
    break;
  case 1:
    handType = HandType::FiveOfAKind;
    break;
  }
}

void Hand::DetermineJokerHandType(const std::unordered_map<int, int>& cards) {
  int jokers{cards.contains(1) ? cards.find(1)->second : 0};
  switch (cards.size()) {
  case 5:
    handType = jokers > 0 ? HandType::OnePair : HandType::HighCard;
    break;
  case 4:
    handType = jokers > 0 ? HandType::ThreeOfAKind : HandType::OnePair;
    break;
  case 3:
    if (std::any_of(cards.begin(), cards.end(),
                    [](const auto& card) { return card.second == 3; })) {
      if (jokers > 0) {
        handType = HandType::FourOfAKind;
      } else {
        handType = HandType::ThreeOfAKind;
      }
    } else {
      if (jokers == 1) {
        handType = HandType::FullHouse;
      } else if (jokers == 2) {
        handType = HandType::FourOfAKind;
      } else {
        handType = HandType::TwoPair;
      }
    }
    break;
  case 2:
    if (std::any_of(cards.begin(), cards.end(),
                    [](const auto& card) { return card.second == 4; })) {
      handType = jokers > 0 ? HandType::FiveOfAKind : HandType::FourOfAKind;
    } else {
      handType = jokers > 0 ? HandType::FiveOfAKind : HandType::FullHouse;
    }
    break;
  case 1:
    handType = HandType::FiveOfAKind;
    break;
  }
}

bool Hand::operator<(const Hand& rhs) {
  if (handType != rhs.handType) {
    return handType < rhs.handType;
  } else {
    return cardValues < rhs.cardValues;
  }
};

std::vector<Hand> ParseInputIntoHands(const std::vector<std::string>& input,
                                      const bool joker) {
  std::vector<Hand> hands;
  hands.reserve(input.size());
  for (const auto& row : input) {
    auto splitRow{myLib::split(row, ' ')};
    hands.emplace_back(Hand{splitRow.at(0), std::stoi(splitRow.at(1)), joker});
  }
  return hands;
}