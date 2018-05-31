/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_evil_str(char *str)
{
	int tmp;
	int a = 0;
	int b = my_strlen(str) - 1;
	int c = (my_strlen(str) - 1) / 2;

	while (a <= c) {
		tmp = str[a];
		str[a++] = str[b];
		str[b--] = tmp;
	}
}
