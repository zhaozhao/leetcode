cmake_minimum_required(VERSION 3.0)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp catch.hpp two_sum.cpp add_two_numbers.cpp longest_substring_without_repeating.cpp median_of_two_sorted_array.cpp kth_largest_element_in_an_array.cpp longest_palindromic_substring.cpp validate_binary_search_tree.cpp binary_tree_level_order_traversal.cpp string_to_integer.cpp nim_game.cpp find_median_from_data_stream.cpp)

add_executable(leetcode ${SOURCE_FILES})