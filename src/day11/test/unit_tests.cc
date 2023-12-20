#include "AoCHelper.h"
#include "galaxy_processing.h"
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

TEST_F(Solutions, PartTwoExampleDummyData) {
  std::vector<std::string> exampleInputDummyData{"..#", "#.."};
  EXPECT_EQ(PartTwo(exampleInputDummyData, 1), 3);
  EXPECT_EQ(PartTwo(exampleInputDummyData, 10), 12);
}
TEST_F(Solutions, PartTwoExampleDummyData2) {
  std::vector<std::string> exampleInputDummyData2{".#", "..", "#."};
  EXPECT_EQ(PartTwo(exampleInputDummyData2, 1), 3);
  EXPECT_EQ(PartTwo(exampleInputDummyData2, 10), 12);
}
TEST_F(Solutions, PartTwoExampleDummyData3) {
  std::vector<std::string> exampleInputDummyData3{"..#", "...", "#.."};
  EXPECT_EQ(PartTwo(exampleInputDummyData3, 1), 4);
  EXPECT_EQ(PartTwo(exampleInputDummyData3, 10), 22);
}
TEST_F(Solutions, PartTwoExampleData10) {
  auto answer{PartTwo(exampleInputPartOne, 10)};
  EXPECT_EQ(answer, 1030);
}

TEST_F(Solutions, PartTwoExampleData100) {
  auto answer{PartTwo(exampleInputPartOne, 100)};
  EXPECT_EQ(answer, 8410);
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput(), 1000000)};
  EXPECT_EQ(answer, 553083047914);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
