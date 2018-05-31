/*
** EPITECH PROJECT, 2022
** 104intersection_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void first_check(int ac, char **av)
{
	int i = 1;

	if (ac != 8 || (atoi(av[1]) < 1 || atoi(av[1]) > 3))
		my_puterror("Usage : ./105torus option a0 a1 a2 a3 a4 n\n", 1);
	while (i < ac) {
		if (my_str_isnum(av[i]) == 0) {
			printf("The argument %d is not a number\n", i);
			exit(84);
		}
		i++;
	}
}