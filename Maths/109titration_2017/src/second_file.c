/*
** EPITECH PROJECT, 2018
** second_file.c
** File description:
** second file of 109titration
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "my.h"

void put_in_board(char **tab, char ***board_x, char ***board_y, int i)
{
	int j = 0;
	int s = 0;

	while (tab[i][j] != ';') {
		(*board_x)[i][j] = tab[i][j];
		j++;
	}
	j++;
	while (tab[i][j] != '\0') {
		(*board_y)[i][s] = tab[i][j];
		s++;
		j++;
	}
}

int do_derivative(char ***x, char ***y, int n, char ***y_s)
{
	double kg = (atof((*x)[n]) - atof((*x)[n - 1])) /
		(atof((*x)[n + 1]) - atof((*x)[n - 1]));
	double kd = (atof((*x)[n + 1]) - atof((*x)[n])) /
		(atof((*x)[n + 1]) - atof((*x)[n - 1]));
	double result;
	double resultsecond;
	double final;
	static double bigger = 0;
	static int save_x = 0;

	result = kg * ((atof((*y)[n]) - atof((*y)[n - 1])) /
		(atof((*x)[n]) - atof((*x)[n - 1])));
	resultsecond = kd * ((atof((*y)[n + 1]) - atof((*y)[n])) /
		(atof((*x)[n + 1]) - atof((*x)[n])));
	final = result + resultsecond;
	if (atoi((*x)[n]) == atof((*x)[n]))
		printf("volume: %d ml -> %.2f\n", atoi((*x)[n]), final);
	else
		printf("volume: %.1f ml -> %.2f\n", atof((*x)[n]), final);
	if (final > bigger) {
		bigger = final;
		save_x = n;
	}
	sprintf((*y_s)[n], "%f", final);
	return (save_x);
}

void second_derivative(char ***x, char ***y, int n, char ***y_s)
{
	double kg = (atof((*x)[n]) - atof((*x)[n - 1])) /
		(atof((*x)[n + 1]) - atof((*x)[n - 1]));
	double kd = (atof((*x)[n + 1]) - atof((*x)[n])) /
		(atof((*x)[n + 1]) - atof((*x)[n - 1]));
	double result;
	double resultsecond;
	double final;

	result = kg * ((atof((*y)[n]) - atof((*y)[n - 1])) /
		(atof((*x)[n]) - atof((*x)[n - 1])));
	resultsecond = kd * ((atof((*y)[n + 1]) - atof((*y)[n])) /
		(atof((*x)[n + 1]) - atof((*x)[n])));
	final = result + resultsecond;
	if (atoi((*x)[n]) == atof((*x)[n]))
		printf("volume: %d ml -> %.2f\n", atoi((*x)[n]), final);
	else
		printf("volume: %.1f ml -> %.2f\n", atof((*x)[n]), final);
	sprintf((*y_s)[n], "%f", final);
}

void display_calcule(float x_start, double start)
{
	if (x_start / (int)x_start == 1)
		printf("volume: %.0f ml -> %.2f\n", x_start, start);
	else
		printf("volume: %.1f ml -> %.2f\n", x_start, start);
}

void do_other_calcule(char ***x, char ***y_s, int n)
{
	double x_start = atof((*x)[n + 1]);
	float first_stop = atof((*x)[n + 2]);
	double start = atof((*y_s)[n + 1]);
	double add = (atof((*y_s)[n + 2]) - atof((*y_s)[n + 1])) /
		((atof((*x)[n + 2]) - atof((*x)[n + 1])) * 10);

	while (x_start < first_stop - 0.1) {
		x_start = x_start + 0.1;
		start += add;
		display_calcule(x_start, start);
	}
}

void display_result(char **max_value_x, char **max_value_y)
{
	int n = 0;

	while (atof(max_value_y[n]) > 0) {
		n++;
	}
	printf("\nEquivalent point at %.1f ml\n", atof(max_value_x[n - 1]));
}

void do_calcule(char ***x, char ***y_s, int n, int i)
{
	double x_start = atof((*x)[n]);
	float first_stop = atof((*x)[n + 1]);
	double start = atof((*y_s)[n]);
	double add = (atof((*y_s)[n + 1]) - atof((*y_s)[n])) /
		((atof((*x)[n + 1]) - atof((*x)[n])) * 10);
	char **max_value_x = malloc(sizeof(char *) * i + 1);
	char **max_value_y = malloc(sizeof(char *) * i + 1);
	int j = 0;

	malloc_tab(&max_value_x, i);
	malloc_tab(&max_value_y, i);
	printf("\nSecond derivative estimated:\n");
	while (x_start < first_stop) {
		display_calcule(x_start, start);
		x_start = x_start + 0.1;
		start += add;
		sprintf(max_value_y[j], "%f", start);
		sprintf(max_value_x[j], "%f", x_start);
		j++;
	}
	do_other_calcule(x, y_s, n);
	display_result(max_value_x, max_value_y);
}

void last_derivative(char ***x, char ***y_s, int i)
{
	int n = 2;
	double zero = 0;

	while (atof((*y_s)[n]) < zero) {
		n++;
	}
	while (atof((*y_s)[n + 1]) > zero) {
		n++;
	}
	do_calcule(x, y_s, n, i);
}

void do_the_programe(char ***board_x, char ***board_y, int i, char ***y_s)
{
	int n = 1;
	int temp = 0;
	char **y_ss = malloc(sizeof(char *) * i + 1);

	malloc_tab(&y_ss, i);
	printf("Derivative:\n");
	while (n != i - 1) {
		temp = do_derivative(board_x, board_y, n, y_s);
		n++;
	}
	printf("\nEquivalent point at %s ml\n\n", (*board_x)[temp]);
	n = 2;
	printf("Second derivative:\n");
	while (n != i - 2) {
		second_derivative(board_x, y_s, n, &y_ss);
		n++;
	}
	last_derivative(board_x, &y_ss, i);
}
