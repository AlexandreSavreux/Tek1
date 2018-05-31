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
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

void my_putchar(char c);

int check_errors(int ac);

int my_atoi(char *str);

int my_strstr(char *s1, char *s2);

char *get_next_line(int fd);

int my_put_nbr(int nb);

char **my_str_to_wordarray(char *str, char letter);

int link_start(int ac, char **av);

int my_putstr(char const *str);

char **prepare_my_map(char *path, int x, int y);

int my_strlen(char const *str);

void my_puterror(char const *str);

int my_printf(char *str, ...);

void *my_memset(void *str, int c, size_t n);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

int my_str_isnum(char const *str);

void my_evil_str(char *str);

void my_array_free(char **array);

int my_parser(char *str, va_list va, int a);

void my_put_nbrbase(long long nb, char const *base);

char *my_strncpy(char *dest, char const *src, int n, int start);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif
