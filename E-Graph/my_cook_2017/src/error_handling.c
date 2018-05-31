/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static int check_line(char *wanted, char *line)
{
	int i = 0;

	while (i < my_strlen(wanted)) {
		if (line[i] != wanted[i])
			break;
		i++;
	}
	if (i == my_strlen(wanted))
		return (0);
	else
		return (84);
}

int env_handler(char **env)
{
	int i = 0;
	int valid = 0;

	if (*env == NULL) {
		my_puterror("No environnement\n");
		return (84);
	}
	while (env[i] != NULL) {
		if (check_line("DISPLAY", env[i]) == 0)
			valid++;
		i++;
	}
	if (valid == 1)
		return (0);
	my_puterror("no graphical environnement");
	return (84);
}

int args_main_handler(int ac, char **av)
{
	if (ac > 2)
		return (84);
	if (ac == 2 && my_strstr("-h", av[1]) == 0)
		return (my_helper());
	return (0);
}