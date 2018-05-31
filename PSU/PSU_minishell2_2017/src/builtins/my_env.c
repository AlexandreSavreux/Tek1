/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_env(shell_t *shell)
{
	if ((my_strstr("env", shell->arguments[0])) == 0) {
		for (int i = 0; shell->env[i] != NULL; i++) {
			my_printf("%s\n", shell->env[i]);
		}
		return (0);
	}
	return (1);
}