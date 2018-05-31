/*
** EPITECH PROJECT, 2022
** 106bombyx
** File description:
** Created by tiflo,
*/
#include "my.h"

void check_errors(char **av)
{
	int i = 1;
	int j = 0;

	while (av[i]) {
		while (av[i][j]) {
			if ((av[i][j] < '0' || av[i][j] > '9') &&
				av[i][j] != '.')
				my_puterror("Invalid char in argument\n", 1);
			++j;
		}
		j = 0;
		++i;
	}
}