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

	if (ac != 9 || (atoi(av[1]) < 1 || atoi(av[1]) > 3)) {
		my_puterror(
			"Usage : ./104intersection option x y z Vx Vy Vz angle/radius\n");
		exit(84);
	}
	while (i < ac) {
		if (my_str_isnum(av[i]) == 0) {
			printf("The argument %d is not a number\n", i);
			exit(84);
		}
		i++;
	}
}

void check_errors(char **av)
{
	if (atoi(av[1]) == 3 && (atoi(av[8]) <= 0 || atoi(av[8]) >= 90)) {
		my_puterror("Invalid angle\n");
		exit(84);
	}
	if (atoi(av[1]) != 3 && atoi(av[8]) <= 0) {
		my_puterror("Invalid radius\n");
		exit(84);
	}
	if (atoi(av[5]) == 0 && atoi(av[6]) == 0 && atoi(av[7]) == 0) {
		my_puterror("Null vector\n");
		exit(84);
	}
}