/*
** EPITECH PROJECT, 2018
** my_arrlen
** File description:
** my_arrlen
*/

#include <stdlib.h>

int my_arrlen(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;
	return (i);
}
