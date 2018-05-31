/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include "sandpile.h"
#include "my.h"
#include <stdlib.h>
#include <string.h>

vector_t *init_end(char **map)
{
	vector_t *end = calloc(1, sizeof(vector_t));

	end->x = (int)strlen(map[0]) - 1;
	end->y = my_arrlen(map) - 1;
	return (end);
}

vector_t *init_pos(char **map)
{
	vector_t *pos = calloc(1, sizeof(vector_t));

	pos->x = (int)strlen(map[0]) / 2;
	pos->y = my_arrlen(map) / 2;
	if (strlen(map[0]) % 2 == 0)
		pos->x--;
	if (my_arrlen(map) % 2 == 0)
		pos->y--;
	return (pos);
}

int check_the_line(char *str)
{
	if (str[0] == str[1] || str[0] == str[2] || str[0] == str[3] ||
		str[1] == str[2] || str[1] == str[3] || str[2] == str[3])
		return (1);
	return (0);
}