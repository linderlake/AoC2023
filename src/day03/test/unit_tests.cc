#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{
      "467..114..", "...*......", "..35..633.", "......#...", "617*......",
      ".....+.58.", "..592.....", "......755.", "...$.*....", ".664.598.."};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "3"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  int answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 4361);
}
TEST_F(Solutions, PartOneExtraData) {
  std::vector<std::vector<std::string>> inputs = {
      {"...........", "..*........", "..100......", "..........."},

      {"...........", "...*.......", "..100......", "..........."},

      {"...........", ".....*.....", "..100......", "..........."},

      {"...........", "...........", "..100*.....", "..........."},

      {"...........", "...........", "..100......", ".....*....."},

      {"...........", "...........", "..100......", "....*......"},

      {"...........", "...........", "..100......", "...*......."},

      {"...........", "...........", "..100......", "..*........"},

      {"...........", "...........", "..100......", ".*........."},

      {"...........", "...........", ".*100......", "..........."},

      {"...........", ".*.........", "..100......", "..........."}};

  for (const auto& input : inputs) {
    EXPECT_EQ(PartOne(input), 100);
  }
}
TEST(PartOneTest, TestStarAnd100Positions) {
  std::vector<std::pair<std::vector<std::string>, int>> testCases = {
      {{"...........", "..*........", "..100......", "..........."}, 100},

      {{"...........", "...*.......", "..100......", "..........."}, 100},

      {{"...........", ".....*.....", "..100......", "..........."}, 100},

      {{"...........", "...........", "..100*.....", "..........."}, 100},

      {{"...........", "...........", "..100......", ".....*....."}, 100},

      {{"...........", "...........", "..100......", "....*......"}, 100},

      {{"...........", "...........", "..100......", "...*......."}, 100},

      {{"...........", "...........", "..100......", "..*........"}, 100},

      {{"...........", "...........", "..100......", ".*........."}, 100},

      {{"...........", "...........", ".*100......", "..........."}, 100},

      {{"...........", ".*.........", "..100......", "..........."}, 100},

      {{"*..........", "100........", "...........", "..........."}, 100},

      {{"*..........", "...........", "100........", "..........."}, 0},

      {{"100........", "*..........", "...........", "..........."}, 100},

      {{"100........", "...........", "*..........", "..........."}, 0},

      {{"*00........", "1..........", "...........", "..........."}, 1},

      {{"100........", "*..........", "...........", "..........."}, 100}};
}

/*
TEST_F(Solutions, PartOneRealData) {
  int answer{PartOne(realInput())};
  EXPECT_EQ(answer, 55447);
}

TEST_F(Solutions, PartTwoExampleData) {
  int answer{PartTwo(exampleInputPartTwo)};
  EXPECT_EQ(answer, 281);
}

TEST_F(Solutions, PartTwoExampleDataRowforRow) {
  std::vector<int> answers{29, 83, 13, 24, 42, 14, 76};
  for (size_t i = 0; i < exampleInputPartTwo.size(); i++) {
    int answer{PartTwo({exampleInputPartTwo[i]})};
    EXPECT_EQ(answer, answers[i]);
  }
}

TEST_F(Solutions, PartTwoRealData) {
  int answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 72706);
}
*/
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
