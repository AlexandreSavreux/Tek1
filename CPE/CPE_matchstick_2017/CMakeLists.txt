cmake_minimum_required(VERSION 3.9)
project(CPE_matchstick_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(CPE_matchstick_2017
        include/my.h
        lib/my/my_parser.c
        lib/my/my_printf.c
        lib/my/my_put_nbr.c
        lib/my/my_put_nbrbase.c
        lib/my/my_put_u_nbrbase.c
        lib/my/my_putchar.c
        lib/my/my_putstr.c
        lib/my/my_strlen.c
        lib/my/my_atoi.c
        lib/my/my_str_isnum.c
        src/get_next_line.c
        include/get_next_line.h
        src/main.c
        Makefile lib/my/my_strncpy.c src/error.c include/matchstick.h src/drawer.c src/goal.c src/ai.c lib/my/my_puterror.c src/error2.c)
