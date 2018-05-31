/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include "ginger.h"
#include "my.h"
#include <string.h>

ginger_t init_ginger(char **av)
{
	int i = 0;
	ginger_t ginger;

	while (!av[i] || strcmp(av[++i], "-m") != 0);
	printf("i = %d\n", i );
	if (!av[i] || !av[i + 1]) {
		ginger.x = -1;
		return (ginger);
	} else if (my_str_isnum(av[i + 1]))
		ginger.moves = atoi(av[i + 1]);
	i = 0;
	while (!av[i] || strcmp(av[++i], "-f") != 0);
	if (!av[i] && !av[i + 1]) {
		ginger.x = -1;
		return (ginger);
	}
	ginger.map_name = strdup(av[i + 1]);
	ginger.x = 0;
	return (ginger);
}