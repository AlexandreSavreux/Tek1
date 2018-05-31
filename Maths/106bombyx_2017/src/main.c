/*
** EPITECH PROJECT, 2022
** 106bombyx
** File description:
** Created by tiflo,
*/
#include "my.h"

void usage()
{
	printf("USAGE\n");
	printf("               ./106bombyx n [k |i0 i1]\n");
	printf("DESCRIPTION\n");
	printf("               n    number of first generation individuals\n");
	printf("               k    growth rate from 1 to 4\n");
	printf("               i0   initial generation (included)\n");
	printf("               i1   final generation (included)\n");
	exit(0);
}

int main(int ac, char **av)
{
	check_errors(av);
	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
			usage();
		else
			return (84);
	}
	check_options(ac, av);
	return (0);
}