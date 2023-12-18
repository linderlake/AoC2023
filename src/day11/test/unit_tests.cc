#include "AoCHelper.h"
#include "placeholder.h"
#include "solutions.h"
#include "gtest/gtest.h"
#include <string>

class Solutions : public ::testing::Test {
protected:
  // clang-format off
  std::vector<std::string> exampleInputPartOne{
      "...#......",
      ".......#..",
      "#.........",
      "..........",
      "......#...",
      ".#........",
      ".........#",
      "..........",
      ".......#..",
      "#...#....."};
  std::vector<std::string> exampleInputPartOneExtraEmpty{
      "............", 
      "....#.......", 
      "........#...", 
      ".#..........", 
      "............", 
      ".......#....",
      "..#.........", 
      "..........#.", 
      "............", 
      "........#...", 
      ".#...#......",
      "............"};
  std::vector<std::string> exampleInputPartOneExtraEmptyFilled{
      ".................",
      ".................",
      "......#..........",
      "...........#.....",
      "..#..............",
      ".................",
      ".................",
      "..........#......",
      "...#.............",
      "..............#..",
      ".................",
      ".................",
      "...........#.....",
      "..#....#.........",
      ".................",
      "................."};
  std::vector<std::string> exampleInputPartTwo{};
  // clang-format on
  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "11"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneDuplicateEmptyRowsAndColumns) {
  DuplicateEmptyRowsAndColumns(exampleInputPartOneExtraEmpty);
  EXPECT_EQ(exampleInputPartOneExtraEmpty, exampleInputPartOneExtraEmptyFilled);
}
TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 374);
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 10154062);
}
/*
TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartTwo)};
  EXPECT_EQ(answer, 281);
}

TEST_F(Solutions, PartTwoExampleDataRowforRow) {
  std::vector<int> answers{29, 83, 13, 24, 42, 14, 76};
  for (size_t i = 0; i < exampleInputPartTwo.size(); i++) {
    auto answer{PartTwo({exampleInputPartTwo[i]})};
    EXPECT_EQ(answer, answers[i]);
  }
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 72706);
}
*/
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
