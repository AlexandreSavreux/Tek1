/*
** EPITECH PROJECT, 2018
** my_del_tild
** File description:
** my_del_tild
*/

#include <stdlib.h>
#include "my.h"
#include <stdio.h>

static int jump_space(char *str, int i)
{
	while (str[i] != '\0' && str[i] == ' ')
		i++;
	return (i);
}

static int res_len(char *str)
{
	int i = jump_space(str, 0);
	int j = 0;

	while (str[i] != '\0') {
		i++;
		j++;
		if (str[i] == ' ') {
			j++;
			i = jump_space(str, i);
		}
	}
	if (j != 0 && str[i - 1] == ' ')
		j--;
	return (j);
}

static char *cpy_res(char *res, char *str, int size)
{
	int i = jump_space(str, 0);
	int j = 0;

	while (str[i] != '\0' && j != size) {
		res[j] = str[i];
		i++;
		j++;
		if (str[i] == ' ') {
			res[j] = str[i];
			j++;
			i = jump_space(str, i);
		}
	}
	res[size] = '\0';
	return (res);
}

char *my_clean_str(char *str)
{
	int size;
	char *res;

	if (str == NULL)
		return (NULL);
	size = res_len(str);
	res = malloc(sizeof(char) * (size + 1));
	if (res == NULL)
		return (NULL);
	res[size] = '\0';
	res = cpy_res(res, str, size);
	return (res);
}