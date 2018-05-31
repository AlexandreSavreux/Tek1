/*
** EPITECH PROJECT, 2017
** main
** File description:
** 101pong
*/

#include <math.h>
#include <stdio.h>
#include "my.h"

int vecteur_vitesse(char **av)
{
	float x = char_to_float(av[4]);
	float y = char_to_float(av[5]);
	float z = char_to_float(av[6]);
	float vx = x - char_to_float(av[1]);
	float vy = y - char_to_float(av[2]);
	float vz = z - char_to_float(av[3]);
	float stock = z;

	x = x + char_to_int(av[7]) * vx;
	y = y + char_to_int(av[7]) * vy;
	z = z + char_to_int(av[7]) * vz;
	printf("%s", "The speed vector coordinates are :\n");
	printf("(%.2f;%.2f;%.2f)\nAt time ", vx, vy, vz);
	printf("t+%d, ball coordinates will be :\n", char_to_int(av[7]));
	printf("(%.2f;%.2f;%.2f)\n", x, y, z);
	if ((stock >= 0 && z > 0) || (stock <= 0 && z < 0))
		return (1);
	return (0);
}

float calcul_angle(char **av)
{
	float xo = char_to_float(av[4]);
	float yo = char_to_float(av[5]);
	float zo = char_to_float(av[6]);
	float vx = xo - char_to_float(av[1]);
	float vy = yo - char_to_float(av[2]);
	float vz = zo - char_to_float(av[3]);
	float k;
	float hypo;
	float sin;

	if (vz == 0)
		return (0);
	k = (-1) * zo / vz;
	vx = xo + k * vx;
	vy = yo + k * vy;
	hypo = sqrt(my_carre(xo - vx) + my_carre(yo - vy) + zo * zo);
	sin = my_abs(zo) / hypo;
	return (asin(sin));
}

int main(int argc, char **argv)
{
	float angle;

	check_arguments(argc, argv);
	if (vecteur_vitesse(argv) == 1) {
		printf("The ball won't reach the bat.\n");
		return (0);
	}
	angle = calcul_angle(argv) * 180 / M_PI;
	printf("The incidence angle is :\n%.2f degrees\n", angle);
}
