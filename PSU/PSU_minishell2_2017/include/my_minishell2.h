/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#ifndef MY_MINISHELL1_H
#define MY_MINISHELL1_H

#include <fcntl.h>

typedef struct shell_s {
	char **path;
	char **cmds;
	char **arguments;
	char *buffer;
	char *cmd;
	char *home;
	pid_t pid;
	char **env;
	int status;
	int ret;
} shell_t;

#endif //PSU_MINISHELL1_MY_MINISHELL1_H
