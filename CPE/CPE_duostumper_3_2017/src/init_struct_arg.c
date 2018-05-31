/*
** EPITECH PROJECT, 2018
** init_struct_arg
** File description:
** init_struct_arg
*

#include "minicut.h"
#include "my.h"
#include <stdlib.h>

int *realloc_int(int *src, int more_alloc)
{
	int *ret;
	int i = 0;

	while (src[i] != -1)
		i++;
	ret = malloc(sizeof(int) * (more_alloc + i));
	i = 0;
	while (src[i] != -1) {
		ret[i] = src[i];
		i++;
	}
	ret[i] = -1;
	free(src);
	return (ret);
}

int my_int_len(int *src)
{
	int i = 0;

	while (src[i] == -1)
		i++;
	return (i);
}

int *get_the_line_nb(char *src, int *ret)
{
	char **tmp = my_str_to_word_array(src, '-', '-');
	int to_add = my_getnbr(tmp[0]);
	int to;

	if (my_arrlen(tmp) == 1)
		if (src[0] == '-')
			to_add = 0;
		else if (src[my_strlen(src) - 1] == '-') {
			ret[my_int_len(ret) - 1]/* = /*this_num();
		} else
			to = my_getnbr(tmp[1]);
}

int *get_this_arg(char *str)
{
	int *ret = malloc(sizeof(int) * 1);
	char **tmp = my_str_to_word_array(str, ',', ',');
	int i = 0;
	int j = 0;

	ret[0] = -1;
	while (tmp[i] != NULL) {
		if (my_str_isnum(tmp[i]) == 1) {
			ret = realloc_int(ret, 1);
			ret[j] = my_getnbr(tmp[i]);
			j++;
		} else {
			ret = get_the_line_nb(tmp[i], ret);
		}
		i++;
	}
}

void init_struct_arg(arg_t *optns, char **arg)
{
	int i = 0;

	while (arg[i] != NULL && my_strncat(arg[i], my_strdup("-d"), 2))
		i++;
	if (my_strlen(arg[i]) == 2)
		optns->delimiter = arg[i + 1][0];
	else
		optns->fields = arg[i][0];
	while (arg[i] != NULL && my_strncat(arg[i], my_strdup("-f"), 2))
		i++;
	if (my_strlen(arg[i] == 2))
		optns->fields = get_this_arg(arg[i + 1]);
	else
		optns->delimiter = get_this_arg(arg[i]);
	while (arg[i] != NULL && my_strncat(arg[i], my_strdup("-c"), 2))
		i++;
	if (my_strlen(arg[i] == 2))
		optns->characters = arg[i + 1][0];
	else
		optns->characters = get_this_arg(arg[i]);
}
*/