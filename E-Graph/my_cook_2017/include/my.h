/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by our libmy.a
*/
#ifndef MY_H_
#define MY_H_

#include "struct.h"
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

void my_putchar(char c);

void manage_excec(char *name);

void my_cmds();

int my_strstr(char *s1, char *s2);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strlen(char const *str);

int my_printf(char *str, ...);

int env_handler(char **env);

int my_helper(void);

int args_main_handler(int ac, char **av);

void my_puterror(char const *str);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

int my_parser(char *str, va_list va, int a);

void my_put_nbrbase(long long nb, char const *base);

char *my_strncpy(char *dest, char const *src, int n, int start);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif
