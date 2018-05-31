/*
** EPITECH PROJECT, 2022
** 106bombyx_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

double resolve(char *eq, double x)
{
	int i;
	double res;

	i = strlen(eq) - 1;
	res = 0;
	while (i >= 0) {
		while (i >= 0 && eq[i] != '*')
			i--;
		i++;
		res *= x;
		res += (float)(eq[i] - 48);
		i -= 2;
	}
	return (res);
}

void calc(int ac, char **av)
{
	int i = 1;
	double x = 0;
	double result1 = 1;

	while (x < 1.001) {
		while (i < ac) {
			result1 *= (resolve(av[i], x) / resolve(av[i + 1], x));
			i += 2;
		}
		if (x == 0)
			printf("%.f -> %.5f\n", x, result1);
		else if (x > 0)
			printf("%g -> %.5f\n", x, result1);
		result1 = i = 1;
		x = x + 0.001;
	}
}