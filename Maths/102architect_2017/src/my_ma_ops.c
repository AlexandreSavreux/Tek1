/*
** EPITECH PROJECT, 2017
** my_ma_ops.c
** File description:
** All matrix calculations and display
*/
#include "my_architect.h"

void my_print_ma(double *matrice)
{
	int i = 0;

	while (i < 9)
	{
		printf("%.2f", (float)(int)matrice[i]);
		if (i != 3 || i != 6 || i != 9)
			i++;
		if (i % 3 == 0)
		{
			printf("\n");
		}
		else
			printf("\t");
	}
}

double my_filler(double *matrice, double x, double y, char type)
{
	matrice[2] = 0;
	matrice[5] = 0;
	matrice[6] = 0;
	matrice[7] = 0;
	matrice[8] = 1;
	switch (type) {
	case 'R' :
		matrice[0] = x;
		matrice[1] = -y;
		matrice[3] = y;
		matrice[4] = x;
		break;
	case 'S' :
		matrice[0] = x;
		matrice[1] = y;
		matrice[3] = y;
		matrice[4] = -x;
		break;
	}
	return (*matrice);
}
