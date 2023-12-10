#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{"Time:      7  15   30",
                                               "Distance:  9  40  200"};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "6"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 288);
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 6209190);
}

TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartOne)};
  EXPECT_EQ(answer, 71503);
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 28545089);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
