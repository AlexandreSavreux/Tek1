/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int victory(char **str)
{
	int i = 0;
	int j = 0;
	int nb = 0;

	while (str[i]) {
		j = 0;
		while (str[i][j]) {
			if (str[i][j] == 'x')
				nb++;
			j++;
		}
		i++;
	}
	if (nb == 14)
		return (1);
	return (0);
}

int link_start(int ac, char **av)
{
	player_t player;
	int my_return = 84;

	player.pid = getpid();
	if (ac == 2) {
		my_return = player1(&player, av[1]);
		if (my_return == 0)
			my_printf("I won\n");
		else if (my_return == 1)
			my_printf("Enemy won\n");
		else
			my_return = 84;
	}
	if (ac == 3) {
		my_return = player2(&player, my_atoi(av[1]), av[2]);
		if (my_return == 0)
			my_printf("I won\n");
		else if (my_return == 1)
			my_printf("Enemy won\n");
		else
			my_return = 84;
	}
	return (my_return);
}