/*
** EPITECH PROJECT, 2018
** my_realloc_array
** File description:
** my_realloc_array
*/

#include <stdlib.h>
#include "my.h"

char **my_realloc_array_w_free(char **array, int more_alloc)
{
	int len = my_arrlen(array);
	char **res = malloc(sizeof(char *) * (len + more_alloc + 1));
	int tmp = 0;

	res[len + more_alloc] = NULL;
	while (array[tmp] != NULL) {
		res[tmp] = array[tmp];
		tmp++;
	}
	return (res);
}
