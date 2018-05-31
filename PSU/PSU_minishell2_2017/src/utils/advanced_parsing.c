/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"

int check_slash(shell_t *shell)
{
	int cpt = 0;

	while (shell->arguments[0][cpt] != '\0') {
		if (shell->arguments[0][cpt] == '/')
			return (1);
		cpt++;
	}
	return (0);
}

int check_path(shell_t *shell)
{
	if (check_slash(shell) == 1) {
		if (access(shell->arguments[0], X_OK) == 0) {
			shell->cmd = shell->arguments[0];
			return (0);
		}
	}
	return (1);
}