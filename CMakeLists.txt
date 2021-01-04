cmake_minimum_required(VERSION 3.17)
project(DSA)

set(CMAKE_CXX_STANDARD 20)

add_executable(DSA main.cpp array.h)

# 'GTest' is the folder with Google Test sources
add_subdirectory(GTest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_Run' is the target name
# 'test*.cpp' are source files with tests
add_executable(Google_Tests_Run tests/test.cpp tests/array_test.cpp)
target_link_libraries(Google_Tests_Run gtest gtest_main)