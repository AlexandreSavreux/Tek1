/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of my_cook
*/
#include "my.h"

int main(int ac, char **av)
{
	my_map_t map;

	check_at_start_errors(ac, av, &map);
	if (map.status == 84)
		return (84);
	create_my_map(&map);
	map.victory = 0 + (map.my_max_stick = map.map[map.size - 1]);
	while (42) {
		my_drawer(&map, map.size, 2);
		my_putstr("Your turn:\n");
		if (live_check(&map) == 6)
			return (0);
		if ((map.status = check_end(&map)) != 0)
			return (map.status);
		my_drawer(&map, map.size, 2);
		ai_main(&map);
		if ((map.status = check_end(&map)) != 0)
			return (map.status);
	}
}
