/*
** EPITECH PROJECT, 2022
** 103cipher_2017
** File description:
** Created by f.louvet,
*/
#include <stdio.h>

void my_print_ma(double *matrice, int size)
{
	int i = 0;

	while (i < size) {
		printf("%.2f", (float)(int)matrice[i]);
		if (i % 3 == 0) {
			printf("\n");
		} else
			printf("\t");
	}
}

double *mult_ma(double *ma, double *ma2)
{
	int size = sizeof(ma) / sizeof(int);
	double ma3[size];

	for (int i; i < size; i++) {
		ma3[i] = ma[i];
	}

	/*	for (int i; )
			ma[0] = ma3[0] * ma2[0] + ma3[1] * ma2[3] + ma3[2] * ma2[6];
		ma[1] = ma3[0] * ma2[1] + ma3[1] * ma2[4] + ma3[2] * ma2[7];
		ma[2] = ma3[0] * ma2[2] + ma3[1] * ma2[5] + ma3[2] * ma2[8];
		ma[3] = ma3[3] * ma2[0] + ma3[4] * ma2[3] + ma3[5] * ma2[6];
		ma[4] = ma3[3] * ma2[1] + ma3[4] * ma2[4] + ma3[5] * ma2[7];
		ma[5] = ma3[3] * ma2[2] + ma3[4] * ma2[5] + ma3[5] * ma2[8];
		ma[6] = ma3[6] * ma2[0] + ma3[7] * ma2[3] + ma3[8] * ma2[6];
		ma[7] = ma3[6] * ma2[1] + ma3[7] * ma2[4] + ma3[8] * ma2[7];
		ma[8] = ma3[6] * ma2[2] + ma3[7] * ma2[5] + ma3[8] * ma2[8];
		return (ma);
	*/
}

char *suppr_spaces(char *str)
{
	int i = 0;
	int j = 0;
	char *str2;

	str2 = malloc(my_strlen(str) + 1);
	while (str[i] != '\0') {
		if (str[i] != ' ') {
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}