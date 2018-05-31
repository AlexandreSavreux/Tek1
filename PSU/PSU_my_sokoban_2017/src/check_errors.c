/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by tiflo,
*/
#include "sokoban.h"

void check_args(int ac, char **av)
{
	if (ac != 2)
		exit(84);
	if (av[1][0] == '-' && av[1][1] == 'h') {
		my_printf("USAGE\n");
		my_printf("\t\t./my_sokoban map\n\n");
		my_printf("DESCRIPTION\n");
		my_printf("\t\tmap\tfile representing the warehouse map, ");
		my_printf(
			"containing '#' for walls,\n\t\t\t'P' for the player");
		my_printf(", 'X' for boxes and 'O' for storage locations.\n");
		exit(0);
	}
}

void check_map(int nb_p, int nb_box, int nb_target)
{
	if (nb_p != 1 || nb_box != nb_target) {
		write(2, "Map is invalid.\n", 17);
		exit(84);
	}
}

void check_ifmap(char *name)
{
	FILE *fd;

	fd = fopen(name, "r");
	if (fd == 0) {
		write(2, "Map not found\n", 22);
		exit(84);
	}
	fclose(fd);
}