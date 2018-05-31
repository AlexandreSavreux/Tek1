/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_home(shell_t *shell)
{
	int i = 0;

	while (shell->env[i]) {
		if (shell->env[i][0] == 'H' && shell->env[i][1] == 'O' &&
			shell->env[i][2] == 'M' && shell->env[i][3] == 'E') {
			shell->home = malloc(
				sizeof(char) * (my_strlen(shell->env[i]) - 4));
			my_pimped_strncpy(shell->home, shell->env[i],
				(my_strlen(shell->env[i]) - 5), 5);
		}
		i++;
	}
}

void my_path(shell_t *shell)
{
	int i = 0;

	while (shell->env[i]) {
		if (my_strncmp(shell->env[i], "PATH=", 5) == 0)
			shell->path = my_str_to_wordarray(&shell->env[i][5],
				':');
		++i;
	}
}
