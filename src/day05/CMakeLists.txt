add_library(day05_lib solutions.cc placeholder.cc)

# Add main executable
add_executable(day05 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day05 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day05 day05_lib AoCHelper)

# Add test executable
add_executable(day05_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day05_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day05_test GTest::gtest GTest::gtest_main day05_lib)
