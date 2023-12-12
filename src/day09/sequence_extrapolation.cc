#include "sequence_extrapolation.h"
#include <algorithm>

int ExtrapolateValues(const std::vector<int>& numberSequence) {
  std::vector<int> nextNumberSequence;
  nextNumberSequence.reserve(numberSequence.size() - 1);
  for (int i = 0; i < static_cast<int>(numberSequence.size() - 1); i++) {
    nextNumberSequence.emplace_back(numberSequence.at(i + 1) -
                                    numberSequence.at(i));
  }

  if (std::all_of(nextNumberSequence.begin(), nextNumberSequence.end(),
                  [](auto i) { return i == 0; })) {
    return numberSequence.at(0);
  }
  return numberSequence.back() + ExtrapolateValues(nextNumberSequence);
};