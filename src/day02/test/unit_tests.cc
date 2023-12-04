#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  // clang-format off
  std::vector<std::string> exampleInput{
      "Game 1: 3 blue, 4 red; 1 red, 2 green, 6 blue; 2 green",
      "Game 2: 1 blue, 2 green; 3 green, 4 blue, 1 red; 1 green, 1 blue",
      "Game 3: 8 green, 6 blue, 20 red; 5 blue, 4 red, 13 green; 5 green, 1 red",
      "Game 4: 1 green, 3 red, 6 blue; 3 green, 6 red; 3 green, 15 blue, 14 red",
      "Game 5: 6 red, 1 blue, 3 green; 2 blue, 1 red, 2 green"};
  // clang-format on

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper a1{"2023", "2"};
    return a1.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  int answer{PartOne(exampleInput)};
  EXPECT_EQ(answer, 8);
}

TEST_F(Solutions, PartOneRealData) {
  int answer{PartOne(realInput())};
  EXPECT_EQ(answer, 1853);
}

TEST_F(Solutions, PartTwoExampleData) {
  int answer{PartTwo(exampleInput)};
  EXPECT_EQ(answer, 2286);
}

TEST_F(Solutions, PartTwoRealData) {
  int answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 72706);
}
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
