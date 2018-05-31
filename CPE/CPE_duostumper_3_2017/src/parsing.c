/*
** EPITECH PROJECT, 2022
** CPE_duostumper_3_2017
** File description:
** Created by tiflo,
*/
#include "my.h"
/*
static int my_optns_pick(char *optn, char *value)
{
	switch (optn[1]) {
	case 'c':
		return (change_width(atoi(value), settings));
	case 'd':
		return (change_height(atoi(value), settings));
	case 'f':
		return (change_referee(value, settings));
	default:
		my_puterror("invalid option");
		return (42);
	}
}

static int optn_without_space(char *str, setting_t *settings)
{
	char value[4];

	if ((str[1] == 'h' || str[1] == 'w') && str[2]) {
		for (int i = 2; str[i] != '\0'; i++)
			value[i - 2] = str[i];
		value[4] = '\0';
		return (my_optns_pick(str, value, settings));
	}
	if (str[1] == 'p') {
		return (my_optns_pick(str, &str[3], settings));
	}
	return (str[1] == 'a') ? my_optns_pick(str, &str[2], settings) : 42;
}

static int pre_check_optns(char **av, int *i, setting_t *settings)
{
	if (av[*i][0] == '-' && av[*i + 1] != NULL && av[*i + 1][0] != '-') {
		if (my_optns_pick(av[*i], av[*i + 1], settings))
			return (84);
	} else if (av[*i][0] == '-' &&
		(av[*i + 1] == NULL || av[*i + 1][0] == '-')) {
		if (optn_without_space(av[*i], settings))
			return (84);
	}
	return (0);
}

int core_optns(char **av, setting_t *settings)
{
	for (int i = 1; av[i] != NULL; i++) {
		if (pre_check_optns(av, &i, settings))
			return (84);
	}
	return (0);
	}*/
