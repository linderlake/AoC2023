add_library(day09_lib solutions.cc sequence_extrapolation.cc)

# Add main executable
add_executable(day09 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day09 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day09 day09_lib AoCHelper)

# Add test executable
add_executable(day09_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day09_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day09_test GTest::gtest GTest::gtest_main day09_lib)
