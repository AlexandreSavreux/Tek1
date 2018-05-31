/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

#include "my.h"

char **arrdup(char **array)
{
	int i = 0;
	char **new_array = malloc(sizeof(char *) * my_arrlen(array));

	while (array[i] != NULL) {
		new_array[i] = my_strdup(array[i]);
		i++;
	}
	free(array);
	return (new_array);
}
