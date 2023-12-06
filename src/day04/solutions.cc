#include "solutions.h"
#include "helper_functions.h"
#include "placeholder.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <unordered_map>

int PartOne(const std::vector<std::string>& input) {
  int answer{};
  for (const auto& row : input) {
    auto splitRow{myLib::split(row, '|')};
    auto splitWinningNumbers{
        myLib::split(myLib::split(splitRow.at(0), ':').at(1), ' ')};
    auto splitPlayedNumbers{myLib::split(splitRow.at(1), ' ')};
    std::vector<int> winningNumbers, playedNumbers;

    std::transform(splitWinningNumbers.begin(), splitWinningNumbers.end(),
                   std::back_inserter(winningNumbers), GetNumber);
    std::transform(splitPlayedNumbers.begin(), splitPlayedNumbers.end(),
                   std::back_inserter(playedNumbers), GetNumber);

    std::sort(winningNumbers.begin(), winningNumbers.end());
    std::sort(playedNumbers.begin(), playedNumbers.end());

    std::vector<int> playedWinningNumbers;
    std::set_intersection(winningNumbers.begin(), winningNumbers.end(),
                          playedNumbers.begin(), playedNumbers.end(),
                          std::back_inserter(playedWinningNumbers));

    if (!playedWinningNumbers.empty()) {
      answer += (1 << (playedWinningNumbers.size() - 1));
    }
  };
  return answer;
}

int PartTwo(const std::vector<std::string>& input) {
  int answer{};
  std::unordered_map<int, int> noOfCards;
  for (size_t i = 1; i <= input.size(); i++) {
    noOfCards.emplace(i, 1);
  }
  for (const auto& row : input) {
    auto splitRow{myLib::split(row, '|')};
    auto cardSplit{myLib::split(splitRow.at(0), ':')};
    int cardNumber{std::stoi(myLib::split(cardSplit.at(0), ' ').at(1))};
    auto splitWinningNumbers{myLib::split(cardSplit.at(1), ' ')};
    auto splitPlayedNumbers{myLib::split(splitRow.at(1), ' ')};
    std::vector<int> winningNumbers, playedNumbers;

    std::transform(splitWinningNumbers.begin(), splitWinningNumbers.end(),
                   std::back_inserter(winningNumbers), GetNumber);
    std::transform(splitPlayedNumbers.begin(), splitPlayedNumbers.end(),
                   std::back_inserter(playedNumbers), GetNumber);

    std::sort(winningNumbers.begin(), winningNumbers.end());
    std::sort(playedNumbers.begin(), playedNumbers.end());

    std::vector<int> playedWinningNumbers;
    std::set_intersection(winningNumbers.begin(), winningNumbers.end(),
                          playedNumbers.begin(), playedNumbers.end(),
                          std::back_inserter(playedWinningNumbers));

    auto noOfTickets = noOfCards.at(cardNumber);
    while (noOfTickets--) {
      for (size_t i = 1; i <= playedWinningNumbers.size(); i++) {
        auto it = noOfCards.find(cardNumber + i);
        if (it == noOfCards.end()) {
          break;
        }
        it->second++;
      }
      answer++;
    }
  };
  return answer;
}
