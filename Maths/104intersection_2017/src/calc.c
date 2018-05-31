/*
** EPITECH PROJECT, 2022
** 104intersection_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_delta(float delta, char **av, float a, float b)
{
	float x1;
	float x2;
	int x = atoi(av[2]);
	int y = atoi(av[3]);
	int z = atoi(av[4]);
	int Vx = atoi(av[5]);
	int Vy = atoi(av[6]);
	int Vz = atoi(av[7]);

	printf("straight line going through the (%d,%d,%d) point and of direction vector (%d,%d,%d)\n",
		x, y, z, Vx, Vy, Vz);
	if (a == 0)
		printf("There is an infinite number of intersection points.\n");
	else if (delta == 0) {
		printf("1 intersection point\n");
		x1 = ((-b) - sqrt(delta)) / (2 * a);
		printf("(%.3f, %.3f, %.3f)\n", x + x1 * Vx, y + x1 * Vy,
			z + x1 * Vz);
	} else if (delta < 0)
		printf("No intersection point.\n");
	else if (delta > 0) {
		printf("2 intersection points\n");
		x2 = ((-b) - sqrt(delta)) / (2 * a);
		x1 = ((-b) + sqrt(delta)) / (2 * a);
		printf("(%.3f, %.3f, %.3f)\n", x + x1 * Vx, y + x1 * Vy,
			z + x1 * Vz);
		printf("(%.3f, %.3f, %.3f)\n", x + x2 * Vx, y + x2 * Vy,
			z + x2 * Vz);
	}
}

void my_operations(char **av)
{
	int opt = atoi(av[1]);
	int R = atoi(av[8]);

	switch (opt) {
	case 1:
		printf("sphere of radius %d\n", R);
		my_sphere(av);
		break;
	case 2:
		printf("cylinder of radius %d\n", R);
		my_cylinder(av);
		break;
	case 3 :
		printf("cone of %d degree angle\n", R);
		my_cone(av);
		break;
	default :
		my_puterror("1 for sphere, 2 for cylinder, 3 for cone\n");
		exit(84);
	}
}
