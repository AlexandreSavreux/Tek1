/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"

void my_execve(shell_t *shell)
{
	execve(shell->cmd, shell->arguments, shell->env);
	free(shell->cmd);
}

int cmd_exist(shell_t *shell)
{
	if (check_slash(shell) == 1 || shell->path == NULL)
		return (0);
	for (int a = 0; shell->path[a] != NULL; a++) {
		shell->cmd = my_cmd_cat(shell->path[a], shell->arguments[0]);
		if ((access(shell->cmd, F_OK)) != -1)
			return (1);
	}
	return (0);
}