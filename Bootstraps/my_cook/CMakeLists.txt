cmake_minimum_required(VERSION 3.9)
project(my_cook C)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_executable(my_cook src/main.c include/my.h include/struct.h)