add_library(day04_lib solutions.cc placeholder.cc)

# Add main executable
add_executable(day04 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day04 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day04 day04_lib AoCHelper)

# Add test executable
add_executable(day04_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day04_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day04_test GTest::gtest GTest::gtest_main day04_lib)
