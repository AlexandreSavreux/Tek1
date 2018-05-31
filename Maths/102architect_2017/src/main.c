/*
** EPITECH PROJECT, 2017
** 102architect.c
** File description:
** Helps a group of architects
*/
#include "my_architect.h"

void my_subcommands(double *result, double *matrice, char **av, int ac)
{
	int i = 3;
	char *str = av[i];
	char arg = str[1];

	while (i < ac) {
		switch (arg) {
		case 'r' :
			my_rotation(result, matrice, av, i);
			i += 2;
			break;
		case 't' :
			my_translation(result, matrice, av, i);
			i += 3;
			break;
		case 'h' :
			my_homothety(result, matrice, av, i);
			i += 3;
			break;
		case 's' :
			my_symetrie(result, matrice, av, i);
			i += 2;
			break;
		}
	}
}

double *mult_matrices(double *matrice, double *ma2)
{
	double ma3[9] = {matrice[0], matrice[1], matrice[2],
			 matrice[3], matrice[4], matrice[5],
			 matrice[6], matrice[7], matrice[8]};

	matrice[0] = ma3[0] * ma2[0] + ma3[1] * ma2[3] + ma3[2] * ma2[6];
	matrice[1] = ma3[0] * ma2[1] + ma3[1] * ma2[4] + ma3[2] * ma2[7];
	matrice[2] = ma3[0] * ma2[2] + ma3[1] * ma2[5] + ma3[2] * ma2[8];
	matrice[3] = ma3[3] * ma2[0] + ma3[4] * ma2[3] + ma3[5] * ma2[6];
	matrice[4] = ma3[3] * ma2[1] + ma3[4] * ma2[4] + ma3[5] * ma2[7];
	matrice[5] = ma3[3] * ma2[2] + ma3[4] * ma2[5] + ma3[5] * ma2[8];
	matrice[6] = ma3[6] * ma2[0] + ma3[7] * ma2[3] + ma3[8] * ma2[6];
	matrice[7] = ma3[6] * ma2[1] + ma3[7] * ma2[4] + ma3[8] * ma2[7];
	matrice[8] = ma3[6] * ma2[2] + ma3[7] * ma2[5] + ma3[8] * ma2[8];
	return (matrice);
}

int main(int ac, char **av)
{
	double	matrice[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
	double	result[3];

	check_error(ac, av);
	result[0] = atof(av[1]);
	result[1] = atof(av[2]);
	result[2] = 1;
	my_subcommands(result, matrice, av, ac);
	my_print_ma(matrice);
	printf("(%s,%s) => (%.2f,%.2f)\n", av[1], av[2], result[0], result[1]);
}
