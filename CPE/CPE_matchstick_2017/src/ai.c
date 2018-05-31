/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int ai_eyes(my_map_t *map)
{
	if (map->line <= 0) {
		map->line = 0;
		return (0);
	}
	if (map->line > map->size || map->line == 0) {
		map->line = 0;
		return (0);
	}
	return (1);
}

int ai_matches(my_map_t *map)
{
	if (map->stick <= 0) {
		map->stick = 0;
		return (0);
	}
	if (map->stick > map->max_stick) {
		map->stick = 0;
		return (0);
	}
	if (map->line > 0)
		if (map->stick > map->map[map->line - 1]) {
			map->stick = 0;
			return (0);
		}
	return (1);
}

int ai_main(my_map_t *map)
{
	long i;

	i = rand() % (map->size + 1);
	map->line = (int)i;
	if (ai_eyes(map) == 0) {
		ai_main(map);
		return (0);
	}
	i = (random() % map->my_max_stick);
	map->stick = (int)i + 1;
	if (ai_matches(map) == 0) {
		ai_main(map);
		return (0);
	}
	my_printf("AI's turn...\nAI removed %d match(es) from line %d\n",
		map->stick, map->line);
	map->victory = 1;
	map->map[map->line - 1] -= map->stick;
	return (0);
}
