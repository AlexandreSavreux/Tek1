/*
** EPITECH PROJECT, 2017
** LIB
** File description:
** show char **
*/

#include "my.h"
#include <stdlib.h>

void my_show_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL) {
		my_putstr(arr[i]);
		my_putchar('\n');
		i++;
	}
}