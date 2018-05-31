cmake_minimum_required(VERSION 3.9)
project(109titration)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(107transfer_2017
        include/my.h
        src/main.c
        Makefile src/error.c src/second_file.c src/sort_number.c)
