/*
** EPITECH PROJECT, 2018
** sort_number.c
** File description:
** sort my number
*/

#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort_number2(char ***x, char ***y, int k)
{
	char *stock = NULL;
	char *stock_y = NULL;
	
	if (atof((*x)[k]) > atof((*x)[k + 1])) {
		stock = strdup((*x)[k]);
		(*x)[k] = strdup((*x)[k + 1]);
		(*x)[k + 1] = strdup(stock);
		stock_y = strdup((*y)[k]);
		(*y)[k] = strdup((*y)[k + 1]);
		(*y)[k + 1] = strdup(stock_y);
	}
	free(stock);
	free(stock_y);
}

void sort_number(char ***x, char ***y, int n)
{
	int i = 0;
	int k = 0;

	while (i != n) {
		while (k != n - 1) {
			sort_number2(x, y, k);
			k++;
		}
		k = 0;
		i++;
	}
}
