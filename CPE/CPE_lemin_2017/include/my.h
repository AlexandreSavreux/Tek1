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
#include <time.h>
#include "get_next_line.h"
#include "lemin.h"

void my_putchar(char c);

int my_atoi(char *str);

int my_strstr(char *wanted, char *s2);

char **my_str_to_wordarray(char *str, char c);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_printf(char *str, ...);

int my_strstr(char *wanted, char *s2);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

int my_str_isnum(char const *str);

int my_parser(char *str, va_list va, int a);

void my_put_nbrbase(long long nb, char const *base);

char *my_strncpy(char *dest, char const *src, int n, int start);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif
