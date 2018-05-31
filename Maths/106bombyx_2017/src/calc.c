/*
** EPITECH PROJECT, 2022
** 105torus_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void two_args(char **av, int i, double k)
{
	double n = atof(av[1]);
	if (atof(av[2]) < 0 || atof(av[1]) < 0)
		my_puterror("Number cannot be lower than 0\n", 1);
	if (atof(av[2]) < 1 || atof(av[2]) > 4)
		my_puterror("Number has to be between 1 and 4\n", 1);
	k = atof(av[2]);
	i = 1;
	printf("%i %.2f\n", i, n);
	while (i < 100) {
		n = k * n * (1000.0 - n);
		n /= 1000.0;
		++i;
		if (n < 0)
			n = 0;
		printf("%i %.2lf\n", i, n);
	}
}

void three_args(char **av, int i, double k)
{
	double n;
	double i0 = atof(av[2]);
	double i1 = atof(av[3]);

	while (k < 4) {
		i = 0;
		n = atof(av[1]);
		for (; i < i0 - 2; i++) {
			n = k * n * (1000.0 - n);
			n /= 1000.0;
		}
		for (; i < i1 - 1; i++) {
			n = k * n * (1000.0 - n);
			n /= 1000.0;
			n < 0 ? n = 0 : 0.0;
			printf("%.2lf %.2lf\n", k, n);
		}
		k += 0.01;
	}
}

void check_options(int ac, char **av)
{
	switch (ac) {
	case 3:
		two_args(av, 1, atof(av[2]));
		break;
	case 4:
		if (my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0 ||
			my_str_isnum(av[3]) == 0)
			my_puterror("Only int allowed\n", 1);
		if (atof(av[2]) > atof(av[3]))
			my_puterror(
				"Second argument lower than the first one\n",
				1);
		if (atof(av[2]) < 0 || atof(av[3]) < 0 || atof(av[1]) < 0)
			my_puterror("Number cannot be lower than 0\n", 1);
		three_args(av, 0, 1.0);
		break;
	default:
		exit(84);
	}
}