#include "AoCHelper.h"
#include "solutions.h"
#include "gtest/gtest.h"

class Solutions : public ::testing::Test {
protected:
  // clang-format off
  std::vector<std::string> exampleInputPartOne{"-L|F7", "7S-7|", "L|7||",
                                               "-L-J|", "L|-JF"};
  std::vector<std::string> exampleInputPartOneExtra{"7-F7-", ".FJ|7", "SJLL7",
                                                    "|F--J", "LJ.LJ"};
  std::vector<std::string> exampleInputPartTwo{
      "...........", 
      ".S-------7.", 
      ".|F-----7|.", 
      ".||.....||.", 
      ".||.....||.",
      ".|L-7.F-J|.", 
      ".|..|.|..|.", 
      ".L--J.L--J.", 
      "..........."};
  std::vector<std::string> exampleInputPartTwoSqueeze{
      "..........", ".S------7.", ".|F----7|.", ".||....||.", ".||....||.",
      ".|L-7F-J|.", ".|..||..|.", ".L--JL--J.", ".........."};
  std::vector<std::string> exampleInputPartTwoLargeExample{
      ".F----7F7F7F7F-7....", ".|F--7||||||||FJ....", ".||.FJ||||||||L7....",
      "FJL7L7LJLJ||LJ.L-7..", "L--J.L7...LJS7F-7L7.", "....F-J..F7FJ|L7L7L7",
      "....L7.F7||L7|.L7L7|", ".....|FJLJ|FJ|F7|.LJ", "....FJL-7.||.||||...",
      "....L---J.LJ.LJLJ..."};

  std::vector<std::string> exampleInputPartTwoLargeExample2{
      "FF7FSF7F7F7F7F7F---7", "L|LJ||||||||||||F--J", "FL-7LJLJ||||||LJL-77",
      "F--JF--7||LJLJ7F7FJ-", "L---JF-JLJ.||-FJLJJ7", "|F|F-JF---7F7-L7L|7|",
      "|FFJF7L7F-JF7|JL---7", "7-L-JL7||F7|L7F-7F7|", "L.L7LFJ|||||FJL7||LJ",
      "L7JLJL-JLJLJL--JLJ.L"};

  // clang-format on
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

TEST_F(Solutions, PartTwoExampleData) {
  auto answer{PartTwo(exampleInputPartTwo)};
  EXPECT_EQ(answer, 4);
}

TEST_F(Solutions, PartTwoExampleDataSqueeze) {
  auto answer{PartTwo(exampleInputPartTwoSqueeze)};
  EXPECT_EQ(answer, 4);
}

TEST_F(Solutions, PartTwoExampleDataLargeExample) {
  auto answer{PartTwo(exampleInputPartTwoLargeExample)};
  EXPECT_EQ(answer, 8);
}

TEST_F(Solutions, PartTwoExampleDataLargeExample2) {
  auto answer{PartTwo(exampleInputPartTwoLargeExample2)};
  EXPECT_EQ(answer, 10);
}

TEST_F(Solutions, PartTwoRealData) {
  auto answer{PartTwo(realInput())};
  EXPECT_EQ(answer, 351);
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
