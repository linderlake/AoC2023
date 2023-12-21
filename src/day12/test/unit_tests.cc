#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{"???.### 1,1,3",
                                               ".??..??...?##. 1,1,3",
                                               "?#?#?#?#?#?#?#? 1,3,1,6",
                                               "????.#...#... 4,1,1",
                                               "????.######..#####. 1,6,5",
                                               "?###???????? 3,2,1"};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "12"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 142);
}

TEST_F(Solutions, PartOneExampleDataRowforRow) {
  std::vector<int> answers{1, 4, 1, 1, 4, 10};
  for (size_t i = 0; i < exampleInputPartOne.size(); i++) {
    auto answer{PartOne({exampleInputPartOne[i]})};
    EXPECT_EQ(answer, answers[i]);
  }
}
/*
TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 55447);
}

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
"
