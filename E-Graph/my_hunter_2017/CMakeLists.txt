# cmake_minimum_required(VERSION <specify CMake version here>)
project(my_hunter_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(my_hunter_2017
        include/my.h
        include/struct.h
        simple_window.c src/my_strdup.c src/int_to_char.c)
