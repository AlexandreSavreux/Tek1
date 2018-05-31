/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include "my.h"

int get_the_good_value(char c, char **arr)
{
	int i = 0;
	int x = 0;
	char *tmp;
	int ret;

	while (arr[i][0] != c)
		i++;
	while (arr[i][x] != ':' && arr[i][x] != '\0')
		x++;
	x++;
	tmp = &arr[i][x];
	ret = my_getnbr(tmp);
	return (ret);
}