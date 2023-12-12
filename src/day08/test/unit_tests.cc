#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{
      "LLR", "", "AAA = (BBB, BBB)", "BBB = (AAA, ZZZ)", "ZZZ = (ZZZ, ZZZ)"};
  std::vector<std::string> exampleInputPartOne2{"RL",
                                                "",
                                                "AAA = (BBB, CCC)",
                                                "BBB = (DDD, EEE)",
                                                "CCC = (ZZZ, GGG)",
                                                "DDD = (DDD, DDD)",
                                                "EEE = (EEE, EEE)",
                                                "GGG = (GGG, GGG)",
                                                "ZZZ = (ZZZ, ZZZ)"};
  std::vector<std::string> exampleInputPartTwo{"LR",
                                               "",
                                               "11A = (11B, XXX)",
                                               "11B = (XXX, 11Z)",
                                               "11Z = (11B, XXX)",
                                               "22A = (22B, XXX)",
                                               "22B = (22C, 22C)",
                                               "22C = (22Z, 22Z)",
                                               "22Z = (22B, 22B)",
                                               "XXX = (XXX, XXX)"};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "8"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 6);
}

TEST_F(Solutions, PartOneExampleData2) {
  auto answer{PartOne(exampleInputPartOne2)};
  EXPECT_EQ(answer, 2);
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 18157);
}

TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartTwo)};
  EXPECT_EQ(answer, 6);
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 14299763833181);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
