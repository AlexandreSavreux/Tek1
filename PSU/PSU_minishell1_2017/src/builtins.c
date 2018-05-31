/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

int check_builtins(shell_t *shell)
{
	my_home(shell);
	if (my_exit(shell) && my_cd(shell) && my_env(shell) &&
		my_setenv(shell) && my_unsetenv(shell))
		return (0);
	return (1);
}