#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  std::vector<std::string> exampleInputPartOne{"seeds: 79 14 55 13",
                                               "",
                                               "seed-to-soil map:",
                                               "50 98 2",
                                               "52 50 48",
                                               "",
                                               "soil-to-fertilizer map:",
                                               "0 15 37",
                                               "37 52 2",
                                               "39 0 15",
                                               "",
                                               "fertilizer-to-water map:",
                                               "49 53 8",
                                               "0 11 42",
                                               "42 0 7",
                                               "57 7 4",
                                               "",
                                               "water-to-light map:",
                                               "88 18 7",
                                               "18 25 70",
                                               "",
                                               "light-to-temperature map:",
                                               "45 77 23",
                                               "81 45 19",
                                               "68 64 13",
                                               "",
                                               "temperature-to-humidity map:",
                                               "0 69 1",
                                               "1 0 69",
                                               "",
                                               "humidity-to-location map:",
                                               "60 56 37",
                                               "56 93 4"};
  std::vector<std::string> exampleInputPartTwo{};

  std::function<std::vector<std::string>()> realInput = []() {
    AoCHelper aocHelper{"2023", "5"};
    return aocHelper.get_input();
  };
};

TEST_F(Solutions, PartOneExampleData) {
  auto answer{PartOne(exampleInputPartOne)};
  EXPECT_EQ(answer, 35);
}

TEST_F(Solutions, PartOneRealData) {
  auto answer{PartOne(realInput())};
  EXPECT_EQ(answer, 174137457);
}

TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartOne)};
  EXPECT_EQ(answer, 46);
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 1493866);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
