cmake_minimum_required(VERSION 3.9)
project(CPE_BSQ_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CPE_BSQ_2017
        include/bsq.h
        include/my.h
        lib/my/my_parser.c
        lib/my/my_printf.c
        lib/my/my_put_nbr.c
        lib/my/my_put_nbrbase.c
        lib/my/my_put_u_nbrbase.c
        lib/my/my_putchar.c
        lib/my/my_putstr.c
        lib/my/my_strlen.c
        src/main.c
        src/algo.c
        Makefile src/parser.c)
