/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "my.h"

int check_env_var(char *str, char *var)
{
	int i = 0;

	if (str == NULL || var == NULL)
		return (84);
	while (str[i] != '\0' && var[i] != '\0' && str[i] != '=') {
		if (var[i] != str[i])
			return (0);
		i++;
	}
	if (str[i] != '=' || var[i] != '\0')
		return (0);
	return (1);
}

int get_env_var(char **env, char *var)
{
	int i = 0;

	while (env[i] != NULL && check_env_var(env[i], var) != 1)
		i++;
	if (env[i] == NULL)
		return (-1);
	return (i);
}

int main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	if (get_env_var(env, "DISPLAY") == -1)
		return (84);
	if (do_start() == 84)
		return (84);
	return (0);
}
