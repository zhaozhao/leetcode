cmake_minimum_required(VERSION 3.0)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp catch.hpp two_sum.cpp add_two_numbers.cpp longest_substring_without_repeating.cpp median_of_two_sorted_array.cpp kth_largest_element_in_an_array.cpp longest_palindromic_substring.cpp validate_binary_search_tree.cpp binary_tree_level_order_traversal.cpp string_to_integer.cpp nim_game.cpp find_median_from_data_stream.cpp wiggle_sort_II.cpp symmetric_tree.cpp reverse_bits.cpp numbers_of_1_bits.cpp merge_two_sorted_lists.cpp sort_list.cpp intersection_of_two_linked_lists.cpp power_of_two.cpp power_of_three.cpp subsets.cpp rotate_array.cpp single_number.cpp combinations.cpp zigzag_conversion.cpp palindrome_number.cpp maximum_subarray.cpp 3sum.cpp move_zeroes.cpp reverse_linked_list.cpp invert_binary_tree.cpp container_with_most_water.cpp trapping_rain_water.cpp remove_duplicates_from_sorted_list.cpp swap_nodes_in_pairs.cpp longest_common_prefix.cpp valid_sudoku.cpp remove_nth_node_from_end_of_list.cpp counting_bits.cpp add_digits.cpp same_tree.cpp valid_parentheses.cpp count_and_say.cpp path_sum.cpp maximum_depth_of_binary_tree.cpp letter_combinations_of_a_phone_number.cpp excel_sheet_column_number.cpp)

add_executable(leetcode ${SOURCE_FILES})