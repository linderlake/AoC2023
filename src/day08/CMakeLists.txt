add_library(day08_lib solutions.cc node.cc)

# Add main executable
add_executable(day08 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day08 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day08 day08_lib AoCHelper)

# Add test executable
add_executable(day08_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day08_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day08_test GTest::gtest GTest::gtest_main day08_lib)
