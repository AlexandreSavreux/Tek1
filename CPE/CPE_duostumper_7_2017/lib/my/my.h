/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int my_getnbr(char *str);

int my_putchar(char c);

void my_sort_int_array(int *tab, int size);

int my_strcmp(char const *s1, char const *s2);

char *my_strncat(char *dest, const char *src, int nb);

int my_put_nbr(int nb);

char *my_strcpy(char *dest, char const *src);

int my_str_isnum(char const *str);

int my_strlen(char const *str);

int my_strncmp(char *s1, char *s2, int n);

int my_putstr(char const *str);

char *my_strcat(char *dest, const char *src);

int my_str_isalpha(char const *str);

int my_str_isprintable(char const *str);

char *my_strncpy(char *dest, char const *src, int n);

char *my_strdup(char const *src);

int my_puterror(char const *);

char *get_next_line(int);

char **my_str_to_word_array(char *, char, char);

char *my_realloc(char *, int);

char *my_clean_str(char *);

char *new_str(int);

char *my_strdup_reac(char const *, int);

char *my_strnldup(char *, int);

int my_arrlen(char **);

char **my_realloc_array(char **, int);

char *my_strnlcat(char *, int);

void free_array(char **);

char **arrdup(char **);

void my_show_array(char **);

char **special_array(void);

int is_in_str(char *, char);

int my_parser(char *str, va_list va, int a);

int my_printf(char *str, ...);

void my_put_nbrbase(long long nb, char const *base);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

#endif