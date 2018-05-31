/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int check_victory(my_map_t *map)
{
	for (int i = 0; i < map->size; i++)
		if (map->map[i] != 0)
			return (0);
	if (map->victory == 1)
		return (2);
	else if (map->victory == 2)
		return (1);
	return (0);
}

int check_end(my_map_t *map)
{
	if (check_victory(map) == 1) {
		my_drawer(map, map->size, 1);
		my_printf("You lost, too bad...\n");
		return (2);
	}
	if (check_victory(map) == 2) {
		my_drawer(map, map->size, 1);
		my_printf("I lost... snif... but I'll get you next time!!\n");
		return (1);
	}
	return (0);
}
