add_library(day11_lib solutions.cc placeholder.cc)

# Add main executable
add_executable(day11 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day11 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day11 day11_lib AoCHelper)

# Add test executable
add_executable(day11_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day11_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day11_test GTest::gtest GTest::gtest_main day11_lib)
