/*
** EPITECH PROJECT, 2022
** 106bombyx
** File description:
** Created by tiflo,
*/
#include "my.h"

int sub_check(char **av, int i, int j)
{
	while (av[i][j]) {
		if (av[i][j] != '*' && (av[i][j] < '0' || av[i][j] > '9') &&
			av[i][j] != '-')
			return (84);
		j++;
	}
	return (0);
}

int check_errors(int ac, char **av)
{
	int i = 1;
	int j = 0;

	if (ac % 2 != 1)
		return (84);
	while (i < ac) {
		if (sub_check(av, i, j) == 84)
			return (84);
		j = 0;
		i++;
	}
	return (0);
}

void usage()
{
	printf("USAGE\n");
	printf("               ./107transfer [num den]\n");
	printf("DESCRIPTION\n");
	printf("               num    polynomial numerator defined");
	printf(" by its coeficients\n");
	printf("               den    polynomial denominator defined");
	printf(" by its coeficients\n");
	exit(0);
}

int main(int ac, char **av)
{
	if (check_errors(ac, av) == 84)
		return (84);
	if (ac == 2) {
		if (av[1][0] == '-' && av[1][1] == 'h' && !av[1][2])
			usage();
		else
			return (84);
	}
	calc(ac, av);
	return (0);
}