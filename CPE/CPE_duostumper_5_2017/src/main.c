/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "text_count.h"
#include "my.h"

char **add_value(char **tmp, char **array)
{
	int i = 0;
	int x = 0;
	char *tmp_str;

	while (tmp[i] != NULL) {
		x = get_the_good_value(tmp[0][0], array);
		tmp_str = itos(x);
		tmp[i] = realloc(tmp[i],
			sizeof(char) * (strlen(tmp[i]) + strlen(tmp_str) + 2));
		strcat(tmp[i], ":");
		strcat(tmp[i], tmp_str);
		i++;
	}
}

char **modify_r(occurence_t *occurence, char **array)
{
	int **to_switch = get_occurence(occurence);
	char **tmp = malloc(sizeof(int) * (10000));
	int i = 0;
	int y = 0;
	int x = 0;

	while (to_switch[y] != NULL) {
		tmp[y] = malloc(sizeof(char) * (len_int(to_switch[y]) * 2) + 1);
		while (to_switch[y][i] != -1) {
			tmp[y][x++] = occurence->character[i];
			tmp[y][x++] = ',';
			tmp[y][x] = '\0';
			i++;
		}
		tmp[y++][x - 1] = '\0';
		x = 0;
		i = 0;
	}
	tmp[y] = NULL;
	add_value(tmp, array);
	return (tmp);
}

int print_array(char **array)
{
	int i = 0;

	while (array[i] != NULL) {
		printf("%s\n", array[i]);
		i++;
	}
	free_array(array);
	return (0);
}

char *get_the_good(char **av)
{
	int i = 1;

	while (strcmp(av[i], "-r") == 0 || strcmp(av[i], "-t") == 0)
		i++;
	return (av[i]);
}

int main(int ac, char **av)
{
	occurence_t *occurence = calloc(1, sizeof(occurence_t));
	char **array;

	if (ac < 2)
		return (84);
	array = my_counter(get_the_good(av), occurence);
	if (get_r_arg(av) == 1) {
		if (array != NULL)
			array = modify_r(occurence, array);
	}
	if (get_t_arg(av) == 1) {
	}
	if (array == NULL)
		return (84);
	return (print_array(array));
}
