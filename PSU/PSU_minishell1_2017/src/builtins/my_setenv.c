/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static int is_alpha_num(shell_t *shell)
{
	int i = 1;

	while (shell->arguments[1][i] != '\0') {
		if ((shell->arguments[1][i] >= 'A' &&
			shell->arguments[1][i] <= 'Z') ||
			(shell->arguments[1][i] >= 'a' &&
				shell->arguments[1][i] <= 'z') ||
			(shell->arguments[1][i] >= '0' &&
				shell->arguments[1][i] <= '9') ||
			shell->arguments[1][i] == '_')
			i++;
		else
			return (1);
	}
	return (0);
}

static int check_if_have_nb(shell_t *shell)
{
	if (my_char_isalpha(shell->arguments[1][0]) == 0) {
		my_puterror(
			"setenv: Variable name must begin with a letter.\n");
		return (1);
	}
	if (is_alpha_num(shell)) {
		my_puterror("setenv: Variable name must contain ");
		my_puterror("alphanumeric characters.\n");
		return (1);
	}
	return (0);
}

static void parser(shell_t *shell, int nb_args)
{
	switch (nb_args) {
	case 1:
		for (int j = 0; shell->env[j] != NULL; j++)
			my_printf("%s\n", shell->env[j]);
		break;
	case 2:
		if (!check_if_have_nb(shell))
			run_my_setenv(shell, shell->arguments[1], "");
		break;
	case 3:
		if (!check_if_have_nb(shell))
			run_my_setenv(shell, shell->arguments[1],
				shell->arguments[2]);
		break;
	default:
		my_puterror("setenv: Too many arguments.\n");
	}
}

int my_setenv(shell_t *shell)
{
	int i = 0;

	if ((my_strstr("setenv", shell->arguments[0])) == 0) {
		for (; shell->arguments[i] != NULL; i++);
		parser(shell, i);
		return (0);
	}
	return (1);
}