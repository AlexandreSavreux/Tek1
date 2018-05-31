/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void print_line(int a, int y, int space, my_map_t *map)
{
	int x = 1;

	my_putchar('*');
	while (space-- >= 0)
		my_putchar(' ');
	while (x++ <= y)
		my_putchar('|');
	space = map->my_max_stick / 2 - a / 2 + (a - x);
	for (int i = -1; i <= space; i++)
		my_putchar(' ');
	my_putstr("*\n");
}

void my_drawer(my_map_t *map, int size, int choice)
{
	int i = 0;
	int y;
	int space;
	int a;

	for (int cpt = 0; cpt <= size * 2; ++cpt)
		my_putchar('*');
	my_putchar('\n');
	y = map->map[i];
	a = map->backup[i];
	for (; i <= size; i++) {
		space = size - i - 1;
		(i > 0) ? print_line(a, y, space, map) : 0;
		y = map->map[i];
		a = map->backup[i];
	}
	for (i = 0; i <= size * 2; ++i)
		my_putchar('*');
	(choice == 2) ? my_putstr("\n\n") : my_putstr("\n");
}

void create_my_map(my_map_t *map)
{
	int j = 0;
	int i = 1;

	if ((map->map = malloc(sizeof(int) * map->size + 1)) == NULL)
		return;
	if ((map->backup = malloc(sizeof(int) * map->size + 1)) == NULL)
		return;
	for (; j < map->size; ++j) {
		map->map[j] = i;
		map->backup[j] = i;
		i += 2;
	}
}