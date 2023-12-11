cmake_minimum_required(VERSION 3.18)

set(CMAKE_TOOLCHAIN_FILE /usr/local/vcpkg/scripts/buildsystems/vcpkg.cmake)

project(aoc2023)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

execute_process(COMMAND bash /workspaces/AoC2023/tools/update_aochelper.sh)
# find Google Test
find_package(GTest CONFIG REQUIRED)

# find curlpp packages
find_package(unofficial-curlpp CONFIG REQUIRED)

# add_library AoCHelper
add_library(AoCHelper STATIC IMPORTED)
set_target_properties(AoCHelper PROPERTIES IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/../lib/AocHelper/libAoCHelper.a)
include_directories(${CMAKE_SOURCE_DIR}/../lib/AoCHelper/include)

link_libraries(AoCHelper unofficial::curlpp::curlpp)

add_subdirectory(day01)
add_subdirectory(day02)
add_subdirectory(day03)
add_subdirectory(day04)
add_subdirectory(day05)
add_subdirectory(day06)
add_subdirectory(day07)
