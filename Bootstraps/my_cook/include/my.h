/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by our libmy.a
*/

#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include "struct.h"

void my_putchar(char c);

int my_isneg(int nb);

int my_put_nbr(int nb);

void my_swap(int *a, int *b);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_getnbr(char const *str);

int my_str_isalpha(char const *str);

int my_str_isnum(char const *str);

int my_str_islower(char const *str);

int my_str_isupper(char const *str);

int my_str_isprintable(char const *str);

int my_showstr(char const *str);

int my_showmem(char const *str, int size);

char *my_strcat(char *dest, char const *src);

char *my_strncat(char *dest, char const *src, int nb);

int my_printf(char *str, ...);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

int my_parser(char *str, va_list va, int a);

void my_put_nbrbase(long long nb, char const *base);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif
