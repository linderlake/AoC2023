add_library(day10_lib solutions.cc placeholder.cc)

# Add main executable
add_executable(day10 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day10 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day10 day10_lib AoCHelper)

# Add test executable
add_executable(day10_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day10_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day10_test GTest::gtest GTest::gtest_main day10_lib)
