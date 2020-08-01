cmake_minimum_required(VERSION 3.0)
project(leetcode)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

file(GLOB SOURCE_FILES "*.cpp")

add_executable(leetcode ${SOURCE_FILES})