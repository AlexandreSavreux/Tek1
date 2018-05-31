/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by our libmy.a
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>

void my_putchar(char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_puterror(char const *str);

int my_strlen(char const *str);

void my_delta(float delta, char **av, float a, float b);

void my_operations(char **av);

void my_sphere(char **av);

void my_cylinder(char **av);

void my_cone(char **av);

int my_printf(char *str, ...);

int my_str_isnum(char const *str);

void check_errors(char **av);

void first_check(int ac, char **av);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

int my_parser(char *str, va_list va, int a);

void my_put_nbrbase(long long nb, char const *base);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif
