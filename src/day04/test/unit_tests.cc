
#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{
      {"Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53"},
      {"Card 2: 13 32 20 16 61 | 61 30 68 82 17 32 24 19"},
      {"Card 3:  1 21 53 59 44 | 69 82 63 72 16 21 14  1"},
      {"Card 4: 41 92 73 84 69 | 59 84 76 51 58  5 54 83"},
      {"Card 5: 87 83 26 28 32 | 88 30 70 12 93 22 82 36"},
      {"Card 6: 31 18 13 56 72 | 74 77 10 23 35 67 36 11"}};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "4"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  int answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 13);
}

TEST_F(Solutions, PartOneExampleDataRowforRow) {
  std::vector<int> answers{8, 2, 2, 1, 0, 0};
  for (size_t i = 0; i < exampleInputPartOne.size(); i++) {
    int answer{PartOne({exampleInputPartOne[i]})};
    EXPECT_EQ(answer, answers[i]);
  }
}

TEST_F(Solutions, PartOneRealData) {
  int answer{PartOne(realInput())};
  EXPECT_EQ(answer, 26443);
}

TEST_F(Solutions, PartTwoExampleData) {
  int answer{PartTwo(exampleInputPartOne)};
  EXPECT_EQ(answer, 30);
}

TEST_F(Solutions, PartTwoRealData) {
  int answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 6284877);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
