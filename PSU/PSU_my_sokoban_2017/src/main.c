/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by f.louvet,
*/
#include "sokoban.h"

int main(int ac, char **av)
{
	char *map;
	char *copy;
	int play = 1;

	check_args(ac, av);
	check_ifmap(av[1]);
	map = make_map(av[1]);
	copy = make_map(av[1]);
	while (play) {
		play = my_sokoban(map, copy);
		map = make_map(av[1]);
		copy = make_map(av[1]);
	}
	return (0);
}