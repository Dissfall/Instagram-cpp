cmake_minimum_required(VERSION 3.0)
project(inslib-test1)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(inslib STATIC ./inslib.h ./inslib.cpp)

add_executable(test1 ./tests/test1.cpp)

target_link_libraries(test1 inslib curlpp curl pthread)