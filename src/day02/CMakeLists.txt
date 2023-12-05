add_library(day02_lib solutions.cc)

# Add main executable
add_executable(day02 main.cc)
# Specify the directories where the compiler can find the header files
target_include_directories(day02 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(day02 day02_lib AoCHelper)

# Add test executable
add_executable(day02_test test/unit_tests.cc)

# Specify the directories where the compiler can find the header files for the test
target_include_directories(day02_test PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

# Link test executable with Google Test
target_link_libraries(day02_test GTest::gtest GTest::gtest_main day02_lib)
