/*
** EPITECH PROJECT, 2018
** get_my_file
** File description:
** get_my_file
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <string.h>

int error(char *str, int len)
{
	int i = 0;

	if (strlen(str) != len)
		return (1);
	while (str[i] != '\0') {
		if (str[i] != '.' && str[i] != 'F' && str[i] != 'T' &&
			str[i] != 'G')
			return (1);
		i++;
	}
}

char **modify_line(char **array)
{
	char *tmp;
	int i = 0;

	while (array[i] != NULL) {
		if (is_charinstr(array[i], '\n'))
			tmp = strndup(array[i], strlen(array[i]) - 1);
		else {
			return (array);
		}
		free(array[i]);
		array[i] = tmp;
		if (error(array[i], (int)strlen(array[0])) == 1)
			return (NULL);
		i++;
	}
	return (array);
}

char **get_my_file(char *name)
{
	int i = 0;
	char **array = malloc(sizeof(char *) * 2);
	FILE *fr = fopen(name, "r");
	size_t index = 0;

	if (fr == NULL || array == NULL)
		return (NULL);
	array[i] = NULL;
	while (getline(&array[i], &index, fr) != -1) {
		i++;
		array = realloc(array, sizeof(char *) * (i + 2));
		array[i] = NULL;
	}
	free(array[i]);
	array[i] = NULL;
	array = modify_line(array);
	if (array == NULL)
		return (NULL);
	fclose(fr);
	return (array);
}
