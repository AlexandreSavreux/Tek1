/*
** EPITECH PROJECT, 2017
** calc.c
** File description:
** all operations needed by 102architect
*/
#include "my_architect.h"
#include <math.h>

double *my_translation(double *result, double *matrice, char **av, int i)
{
	double Tx = atof(av[i + 1]);
	double Ty = atof(av[i + 2]);

	matrice[2] += Tx;
	matrice[5] += Ty;
	printf("Translation by the vector (%.0f, %.0f)\n", Tx, Ty);
	result[0] += Tx;
	result[1] += Ty;
	return (result);
}

double *my_homothety(double *result, double *matrice, char **av, int i)
{
	double Hx = atof(av[i + 1]);
	double Hy = atof(av[i + 2]);

	matrice[0] *= Hx;
	matrice[1] *= Hx;
	matrice[2] *= Hx;
	matrice[3] *= Hy;
	matrice[4] *= Hy;
	matrice[5] *= Hy;
	printf("Homothety by the ratios %.0f and %.0f\n", Hx, Hy);
	result[0] *= Hx;
	result[1] *= Hy;
	return (result);
}

double *my_rotation(double *result, double *matrice, char **av, int i)
{
	double matrice_rotation[9];
	double a = atof(av[i + 1]);
	double Rx = cos(a);
	double Ry = sin(a);
	double tmp;

	a = (a * M_PI) / 180;
	my_filler(&matrice_rotation[0], Rx, Ry,'R');
	mult_matrices(&matrice[0], &matrice_rotation[0]);
	printf("Rotation at a %s degree angle\n", av[i + 1]);
	tmp = result[0];
	result[0] = tmp * matrice_rotation[0] + result[1] * matrice_rotation[1];
	result[1] = tmp * matrice_rotation[3] + result[1] * matrice_rotation[4];
	return (result);
}

double *my_symetrie(double *result, double *matrice, char **av, int i)
{
	double matrice_symetrie[9];
	double a = atof(av[i + 1]);
	double Sx = cos(2 * a);
	double Sy = sin(2 * a);
	double tmp;

	a = (a * M_PI) / 180;
	my_filler(&matrice_symetrie[0], Sx, Sy, 'S');
	mult_matrices(&matrice[0], &matrice_symetrie[0]);
	printf("Symmetry about an axis inclined with an angle of %s degrees\n",
	       av[i + 1]);
	tmp = result[0];
	result[0] = tmp * matrice_symetrie[0] + result[1] * matrice_symetrie[1];
	result[1] = tmp * matrice_symetrie[3] + result[1] * matrice_symetrie[4];
	return (result);
}
