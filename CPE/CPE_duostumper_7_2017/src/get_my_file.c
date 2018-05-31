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

char **modify_line(char **array)
{
	char *tmp;
	int i = 0;

	while (array[i] != NULL) {
		if (is_in_str(array[i], '\n'))
			tmp = strndup(array[i], strlen(array[i]) - 1);
		else {
			return (array);
		}
		free(array[i]);
		array[i] = tmp;
		i++;
	}
	return (array);
}

char **check_array(char **arr)
{
	int i = 0;

	while (arr[i] != NULL) {
		if (strlen(arr[i]) == 0 && arr[i][0] == '\0')
			return (NULL);
		i++;
	}
	return (arr);
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
	array = check_array(array);
	return (array);
}
