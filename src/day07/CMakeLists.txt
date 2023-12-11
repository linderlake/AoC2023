add_library(day07_lib solutions.cc hand.cc)

# Add main executable
add_executable(day07 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day07 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day07 day07_lib AoCHelper)

# Add test executable
add_executable(day07_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day07_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day07_test GTest::gtest GTest::gtest_main day07_lib)
