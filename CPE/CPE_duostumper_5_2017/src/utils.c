/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "text_count.h"

int len_int(int *src)
{
	int i = 0;

	while (src[i] != -1)
		i++;
	return (i);
}

int get_r_arg(char **array)
{
	int i = 0;

	while (array[i] != NULL) {
		if (strcmp(array[i], "-r") == 0) {
			return (1);
		}
		i++;
	}
	return (0);
}

int get_t_arg(char **array)
{
	int i = 0;

	while (array[i] != NULL) {
		if (strcmp(array[i], "-t") == 0)
			return (1);
		i++;
	}
	return (0);
}

int *get_the_nb(int nb, int *src)
{
	int i = 0;
	int *ret = malloc(sizeof(int) * 1);
	int ret_x = 0;

	while (src[i] != -1) {
		if (src[i] == nb) {
			ret[ret_x] = src[i];
			src[i] = 0;
			ret_x++;
			ret = realloc(ret, sizeof(int) * (ret_x + 1));
			ret[ret_x] = -1;
		}
		i++;
	}
	return (ret);
}

int **get_occurence(occurence_t *occurence)
{
	int i = 0;
	int y = 0;
	int **ret = malloc(sizeof(int *) * 1);

	while (occurence->nb_of_occurences[i] != -1) {
		if (occurence->nb_of_occurences[i] != 0) {
			ret[y] = get_the_nb(occurence->nb_of_occurences[i],
				occurence->nb_of_occurences);
			y++;
			ret = realloc(ret, sizeof(int *) * (y + 1));
			ret[y] = NULL;
		}
		i++;
	}
	return (ret);
}