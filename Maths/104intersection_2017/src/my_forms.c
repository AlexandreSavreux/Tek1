/*
** EPITECH PROJECT, 2022
** 104intersection_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_sphere(char **av)
{
	float a;
	float b;
	float c;
	float delta;

	a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) + pow(atof(av[7]), 2);
	b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6])) +
		(2 * atof(av[4]) * atof(av[7]));
	c = (pow(atof(av[2]), 2) + pow(atof(av[3]), 2) + pow(atof(av[4]), 2)) -
		pow(atof(av[8]), 2);
	delta = b * b - 4 * a * c;
	my_delta(delta, av, a, b);
}

void my_cylinder(char **av)
{
	float a;
	float b;
	float c;
	float delta;

	a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2);
	b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6]));
	c = (pow(atof(av[2]), 2) + pow(atof(av[3]), 2)) - pow(atof(av[8]), 2);
	delta = b * b - 4 * a * c;
	my_delta(delta, av, a, b);
}

void my_cone(char **av)
{
	float a;
	float b;
	float c;
	float delta;
	double angle = (atof(av[8]) * M_PI) / 180;

	a = pow(atof(av[5]), 2) + pow(atof(av[6]), 2) -
		(pow(atof(av[7]), 2) * pow(tan(angle), 2));
	b = (2 * atof(av[2]) * atof(av[5])) + (2 * atof(av[3]) * atof(av[6])) -
		(2 * atof(av[4]) * atof(av[7]) * pow(tan(angle), 2));
	c = pow(atof(av[2]), 2) + pow(atof(av[3]), 2) -
		pow(atof(av[4]), 2) * pow(tan(angle), 2);
	delta = b * b - 4 * a * c;
	my_delta(delta, av, a, b);
}