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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


void my_putchar(char c);

int my_atoi(char *str);

int my_strstr(char *s1, char *s2);

char *get_next_line(int fd);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_printf(char *str, ...);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

int my_str_isnum(char const *str);

int my_parser(char *str, va_list va, int a);

void my_put_nbrbase(long long nb, char const *base);

char *my_strncpy(char *dest, char const *src, int n, int start);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif
