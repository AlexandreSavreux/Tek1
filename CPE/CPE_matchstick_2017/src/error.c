/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int check_matches(my_map_t *map)
{
	free(map->str);
	if (map->stick <= 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		map->stick = 0;
		return (0);
	}
	if (map->stick > map->max_stick) {
		my_printf("Error: you cannot remove");
		my_printf(" more than %d matches per turn\n", map->max_stick);
		map->stick = 0;
		return (0);
	}
	if (map->stick > map->map[map->line - 1]) {
		my_printf("Error: not enough matches on this line\n");
		map->stick = 0;
		return (0);
	}
	return (1);
}

int check_line(my_map_t *map)
{
	free(map->str);
	if (map->line < 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		map->line = 0;
		return (0);
	}
	if (map->line > map->size || map->line == 0) {
		my_printf("Error: this line is out of range\n");
		map->line = 0;
		return (0);
	}
	return (1);
}

int live_check(my_map_t *map)
{
	my_printf("Line: ");
	if ((map->str = get_next_line(0)) == NULL)
		return (6);
	if (my_str_isnum(map->str) == 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (live_check(map));
	}
	map->line = my_printf("Player removed %d match(es) from line %d\n", map->stick,
		map->line);
	map->map[map->line - 1] -= map->stick;
	map->victory = 2;_atoi(map->str);
	if (check_line(map) == 0)
		return (live_check(map));
	my_putstr("Matches: ");
	if ((map->str = get_next_line(0)) == NULL)
		return (6);
	if (my_str_isnum(map->str) == 0) {
		my_printf("Error: invalid input (positive number expected)\n");
		return (live_check(map));
	}
	map->stick = my_atoi(map->str);
	if (check_matches(map) == 0)
		return (live_check(map));
	my_printf("Player removed %d match(es) from line %d\n", map->stick,
		map->line);
	map->map[map->line - 1] -= map->stick;
	map->victory = 2;
	return (1);
}

int first_check(int ac, char **av)
{
	if (ac != 3)
		return (84);
	if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
		return (84);
	return (0);
}

void check_at_start_errors(int ac, char **av, my_map_t *map)
{
	map->status = 0;
	if (first_check(ac, av) == 0) {
		map->size = my_atoi(av[1]);
		map->max_stick = my_atoi(av[2]);
	}
	if (map->size > 99 || map->size < 2)
		map->status = 84;
	if (map->max_stick < 0)
		map->status = 84;
}