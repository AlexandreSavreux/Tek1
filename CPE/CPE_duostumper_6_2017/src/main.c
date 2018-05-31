/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/

#include "sandpile.h"
#include "my.h"
#include <string.h>

int main(int ac, char **av)
{
	char **map;
	vector_t *pos;
	vector_t *end;
	int nb;

	if (ac != 4)
		return (84);
	map = get_my_file(av[1], av[2]);
	if (check_the_line(av[2]) == 1)
		return (84);
	if (map == NULL)
		return (84);
	end = init_end(map);
	pos = init_pos(map);
	if (!my_str_isnum(av[3]))
		return (84);
	nb = atoi(av[3]);
	my_show_array(map);
	printf("Initial map\n\n");

	for (int i = 0; i < nb; i++) {
		map = if_unstable(av[2], pos, end, map);
	}
	my_show_array(map);
}
