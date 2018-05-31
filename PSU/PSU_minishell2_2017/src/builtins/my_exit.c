/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_exit(shell_t *shell)
{
	if ((my_strstr("exit", shell->arguments[0])) == 0) {
		if (shell->arguments[1] == NULL)
			exit(shell->ret);
		if (my_str_isnum(shell->arguments[1]))
			exit(my_atoi(shell->arguments[1]));
		my_puterror("exit: Expression Syntax.\n");
		return (0);
	}
	return (1);
}