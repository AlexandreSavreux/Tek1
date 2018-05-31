/*
** EPITECH PROJECT, 2022
** 104intersection_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_bisec(char **av, double x, double x1, double x2)
{
	double xn;
	double fxn;
	double fx1;
	double pt1 = 0;
	double pt2 = 1;
	double x3 = atoi(av[5]);
	double x4 = atoi(av[6]);

	for (int i = 1; i <= 250; i++) {
		if (round(pt1 * pow(10, atoi(av[7]))) ==
			round(pt2 * pow(10, atoi(av[7]))))
			exit(EXIT_SUCCESS);
		xn = (pt1 + pt2) / 2;
		fxn = (x4 * pow(xn, 4)) + (x3 * pow(xn, 3)) +
			(x2 * pow(xn, 2)) + (x1 * xn) + x;
		fx1 = ((x4 * pow(pt1, 4)) + (x3 * pow(pt1, 3)) +
			(x2 * pow(pt1, 2)) + (x1 * pt1) + x);
		if (fx1 * fxn < 0)
			pt2 = xn;
		else
			pt1 = xn;
		if (i <= atoi(av[7]))
			printf("x = %.*f\n", i, xn);
		else
			my_printer(av, xn);
	}
}

void my_newton(char **av, double x, double x1, double x2)
{
	double xn = 0.5;
	double xn2;
	double fxn;
	double fpxn;
	double x3 = atoi(av[5]);
	double x4 = atoi(av[6]);

	for (int i = 0; i <= 250; i++) {
		fxn = (x4 * pow(xn, 4)) + (x3 * pow(xn, 3)) +
			(x2 * pow(xn, 2)) + (x1 * xn) + x;
		fpxn = (4 * (x4 * pow(xn, 3))) + (3 * (x3 * pow(xn, 2))) +
			(2 * x2 * xn) + x1;
		if (fpxn == 0)
			my_puterror("Division by zero.", 1);
		xn2 = xn - (fxn / fpxn);
		if (round(xn * pow(10, atoi(av[7]))) ==
			round(xn2 * pow(10, atoi(av[7]))))
			exit(EXIT_SUCCESS);
		xn = xn2;
		my_printer(av, xn);
	}
}

void my_secant(char **av, double x, double x1, double x2)
{
	double pt1 = 0.4;
	double pt2 = 0.7811;
	double f1 = 0;
	double f2 = 0;
	double x3 = atoi(av[5]);
	double x4 = atoi(av[6]);
	double xn;

	for (int i = 0; i <= 250; i++) {
		if (round(pt1 * pow(10, atoi(av[7]))) ==
			round(pt2 * pow(10, atoi(av[7]))))
			exit(EXIT_SUCCESS);
		f1 = (x4 * pow(pt1, 4)) + (x3 * pow(pt1, 3)) +
			(x2 * pow(pt1, 2)) + (x1 * pt1) + x;
		f2 = (x4 * pow(pt2, 4)) + (x3 * pow(pt2, 3)) +
			(x2 * pow(pt2, 2)) + (x1 * pt2) + x;
		if ((f2 - f1) == 0)
			my_puterror("Division by zero.", 1);
		xn = pt2 - ((f2) * (pt2 - pt1) / (f2 - f1));
		my_printer(av, xn);
		pt1 = pt2;
		pt2 = xn;
	}
}

void my_operations(char **av)
{
	int opt = atoi(av[1]);
	double x = atoi(av[2]);
	double x1 = atoi(av[3]);
	double x2 = atoi(av[4]);

	switch (opt) {
	case 1:
		my_bisec(av, x, x1, x2);
		break;
	case 2:
		printf("x = 0.5\n");
		my_newton(av, x, x1, x2);
		break;
	case 3:
		printf("x = 0.5\n");
		my_secant(av, x, x1, x2);
		break;
	default:
		my_puterror("Invalid option", 1);
	}
}
