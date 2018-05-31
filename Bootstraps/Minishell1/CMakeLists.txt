cmake_minimum_required(VERSION 3.9)
project(PSU_minishell1)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(PSU_minishell1
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
        Makefile include/my_bool.h)
