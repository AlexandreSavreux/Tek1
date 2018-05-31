cmake_minimum_required(VERSION 3.9)
project(CPE_corewar_2017)

set(CMAKE_CXX_STANDARD 11)

include_directories(asm/include
        vm/include
        champions/include)

add_executable(CPE_corewar_2017
        champions/include/my.h
       champions/lib/my/my_parser.c
        champions/lib/my/my_printf.c
        champions/lib/my/my_put_nbr.c
        champions/lib/my/my_put_nbrbase.c
        champions/lib/my/my_put_u_nbrbase.c
        champions/lib/my/my_putchar.c
        champions/lib/my/my_putstr.c
        champions/lib/my/my_strlen.c
        champions/lib/my/my_atoi.c
        champions/lib/my/my_str_isnum.c
        champions/include/get_next_line.h
        Makefile champions/lib/my/my_strncpy.c
        asm/include/my.h
        asm/lib/my/my_parser.c
        asm/lib/my/my_printf.c
        asm/lib/my/my_put_nbr.c
        asm/lib/my/my_put_nbrbase.c
        asm/lib/my/my_put_u_nbrbase.c
        asm/lib/my/my_putchar.c
        asm/lib/my/my_putstr.c
        asm/lib/my/my_strlen.c
        asm/lib/my/my_atoi.c
        asm/lib/my/my_str_isnum.c
        asm/include/get_next_line.h
        asm/lib/my/my_strncpy.c
        vm/include/my.h
        vm/lib/my/my_parser.c
        vm/lib/my/my_printf.c
        vm/lib/my/my_put_nbr.c
        vm/lib/my/my_put_nbrbase.c
        vm/lib/my/my_put_u_nbrbase.c
        vm/lib/my/my_putchar.c
        vm/lib/my/my_putstr.c
        vm/lib/my/my_strlen.c
        vm/lib/my/my_atoi.c
        vm/lib/my/my_str_isnum.c
        vm/include/get_next_line.h
        vm/lib/my/my_strncpy.c asm/main.c)
