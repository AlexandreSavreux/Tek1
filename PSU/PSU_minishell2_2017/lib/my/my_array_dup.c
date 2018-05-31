/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static int my_arrlen(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
		i++;
	return (i);
}

char **my_array_dup(char **array)
{
	int i = 0;
	char **new_array = malloc(sizeof(char *) * (my_arrlen(array) + 1));

	while (array[i] != NULL) {
		new_array[i] = my_strdup(array[i]);
		i++;
	}
	new_array[i] = NULL;
	return (new_array);
}
