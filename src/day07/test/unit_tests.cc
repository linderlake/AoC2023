#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{
      "32T3K 765", "T55J5 684", "KK677 28", "KTJJT 220", "QQQJA 483"};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "7"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 6440);
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 247961593);
}

TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartOne)};
  EXPECT_EQ(answer, 5905);
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 248750699);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
