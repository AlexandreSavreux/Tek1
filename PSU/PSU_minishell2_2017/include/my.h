/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** Contains the prototypes of all the functions exposed by our libmy.a
*/
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#include <unistd.h>
#include <signal.h>
#include "my_minishell2.h"

#ifndef MY_H_
	#define MY_H_

void my_putchar(char c);

void manage_excec(char *name);

int my_strstr(char *s1, char *s2);

int my_cd(shell_t *shell);

void my_execve(shell_t *shell);

void my_show_array(char **array);

int check_slash(shell_t *shell);

int check_path(shell_t *shell);

int cmd_exist(shell_t *shell);

char *my_cmd_cat(char *dest, char const *src);

int my_exit(shell_t *shell);

int my_shell(shell_t *shell);

int my_put_nbr(int nb);

int my_putstr(char const *str);

int my_strlen(char const *str);

char *my_clean_str(char *str);

int check_builtins(shell_t *shell);

int my_printf(char *str, ...);

char *recup_from_env(char *wanted, char **env);

int my_signals(int signal);

char *my_strcpy(char *dest, char const *src);

int my_char_isalpha(char str);

void my_puterror(char const *str);

int my_flags2(char c, va_list str);

void my_flags(char c, va_list str);

char **my_str_to_wordarray(char *str, char letter);

void my_home(shell_t *shell);

void my_array_free(char **array);

void my_path(shell_t *shell);

void run_my_setenv(shell_t *shell, char *to_change, char *new_value);

void run_my_unsetenv(char ***env, char *to_unset);

char *get_next_line(int fd);

int my_setenv(shell_t *shell);

int my_unsetenv(shell_t *shell);

int my_env(shell_t *shell);

char *my_strdup(const char *src);

int my_strncmp(const char *str1, const char *str2, int nb);

char *my_strncat(char *dest, char const *str, int nb);

int my_parser(char *str, va_list va, int a);

char *my_strcat(char *dest, char const *src);

void my_put_nbrbase(long long nb, char const *base);

char *my_strncpy(char *dest, char const *src, int n);

char *my_pimped_strncpy(char *dest, char const *src, int n, int start
);

int my_atoi(char *str);

void ctrl_c_handler(int debug);

int my_str_isnum(char const *str);

void my_put_u_nbrbase(long long unsigned nb, char const *base);

char **my_array_dup(char **array);

int my_builtins(shell_t *shell, char ***env);

#endif
