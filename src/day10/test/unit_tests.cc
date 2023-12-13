#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{"-L|F7", "7S-7|", "L|7||",
                                               "-L-J|", "L|-JF"};
  std::vector<std::string> exampleInputPartOneExtra{"7-F7-", ".FJ|7", "SJLL7",
                                                    "|F--J", "LJ.LJ"};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "10"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 4);
}

TEST_F(Solutions, PartOneExampleDataExtra) {
  auto answer{PartOne(exampleInputPartOneExtra)};
  EXPECT_EQ(answer, 8);
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 6768);
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
