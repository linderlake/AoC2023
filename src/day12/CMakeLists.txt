add_library(day12_lib solutions.cc placeholder.cc)

# Add main executable
add_executable(day12 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day12 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day12 day12_lib AoCHelper)

# Add test executable
add_executable(day12_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day12_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day12_test GTest::gtest GTest::gtest_main day12_lib)
