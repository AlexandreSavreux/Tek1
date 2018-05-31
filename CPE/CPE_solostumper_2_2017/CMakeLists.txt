cmake_minimum_required(VERSION 3.9)
project(CPE_solostumper_2_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CPE_solostumper_2_2017
        Makefile src/main.c include/my.h lib/my/my_strdup.c)
