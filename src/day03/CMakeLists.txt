add_library(day03_lib solutions.cc symbol_processing.cc)

# Add main executable
add_executable(day03 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day03 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day03 day03_lib AoCHelper)

# Add test executable
add_executable(day03_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day03_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day03_test GTest::gtest GTest::gtest_main day03_lib)
