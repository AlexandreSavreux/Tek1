/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/

#include "my.h"
#include "get_next_line.h"
#include "ginger.h"
#include <fcntl.h>

int main(int ac, char **av)
{
	ginger_t ginger = init_ginger(av);
	char **arr;

	if (ginger.x == -1) {
		free_array(arr);
		return (84);
	}
	arr = get_my_file(av[1]);
	printf("moves : %d && map_name = %s\n", ginger.moves, ginger.map_name);
	if (!arr)
		return (0);
	my_show_array(arr);
//	while (!finish(ginger))
	free_array(arr);
	return (0);
}
