cmake_minimum_required(VERSION 3.0)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp catch.hpp two_sum.cpp add_two_numbers.cpp longest_substring_without_repeating.cpp)

add_executable(leetcode ${SOURCE_FILES})