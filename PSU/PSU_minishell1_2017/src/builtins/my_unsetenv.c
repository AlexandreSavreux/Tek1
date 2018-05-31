/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_unsetenv(shell_t *shell)
{
	int i = 0;

	if ((my_strstr("unsetenv", shell->arguments[0])) == 0) {
		for (; shell->arguments[i] != NULL; i++);
		if (i == 1) {
			my_puterror(shell->arguments[0]);
			my_puterror(": Too few arguments.\n");
			return (0);
		}
		for (int j = 1; shell->arguments[j] != NULL; j++)
			run_my_unsetenv(&shell->env, shell->arguments[j]);
		return (0);
	}
	return (1);
}