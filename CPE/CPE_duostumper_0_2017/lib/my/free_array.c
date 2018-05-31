/*
** EPITECH PROJECT, 2018
** free_array
** File description:
** free_array
*/

#include <stdlib.h>
#include "my.h"

void free_array(char **tmp)
{
	int i = my_arrlen(tmp) - 1;

	while (i >= 0) {
		free(tmp[i]);
		i--;
	}
	free(tmp);
}
