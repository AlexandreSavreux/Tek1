cmake_minimum_required(VERSION 3.9)
project(107transfer_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(107transfer_2017
        include/my.h
        lib/my/my_parser.c
        lib/my/my_printf.c
        lib/my/my_put_nbr.c
        lib/my/my_put_nbrbase.c
        lib/my/my_put_u_nbrbase.c
        lib/my/my_putchar.c
        lib/my/my_putstr.c
        lib/my/my_strlen.c
        lib/my/my_str_to_wordarray.c
        src/main.c
        Makefile lib/my/my_puterror.c src/calc.c)
