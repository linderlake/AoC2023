add_library(day06_lib solutions.cc)

# Add main executable
add_executable(day06 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day06 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day06 day06_lib AoCHelper)

# Add test executable
add_executable(day06_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day06_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day06_test GTest::gtest GTest::gtest_main day06_lib)
