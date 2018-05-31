cmake_minimum_required(VERSION 3.9)
project(Corewar C)

include_directories(include)

set(CMAKE_C_STANDARD 99)

add_executable(Corewar
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
        src/main.c
        Makefile lib/my/my_strncpy.c "include/Maxime la pute.h")