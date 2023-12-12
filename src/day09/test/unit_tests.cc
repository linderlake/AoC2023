#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{
      "0 3 6 9 12 15", "1 3 6 10 15 21", "10 13 16 21 30 45"};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "9"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 114);
}

TEST_F(Solutions, PartOneExampleDataRowforRow) {
  std::vector<int> answers{18, 28, 68};
  for (size_t i = 0; i < exampleInputPartOne.size(); i++) {
    auto answer{PartOne({exampleInputPartOne[i]})};
    EXPECT_EQ(answer, answers[i]);
  }
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 2105961943);
}

TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartOne)};
  EXPECT_EQ(answer, 2);
}

TEST_F(Solutions, PartTwoExampleDataRowforRow) {
  std::vector<int> answers{-3, 0, 5};
  for (size_t i = 0; i < exampleInputPartOne.size(); i++) {
    auto answer{PartTwo({exampleInputPartOne[i]})};
    EXPECT_EQ(answer, answers[i]);
  }
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 1019);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}