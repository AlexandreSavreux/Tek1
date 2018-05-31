/*
** EPITECH PROJECT, 2018
** str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "my.h"

int compt_str(char const *str, char separator)
{
	int nbr_word = 0;

	if (str[0] != separator)
		nbr_word++;
	for (int i = 0; str[i] != 0; i++)
		if (str[i] == separator && str[i + 1] != separator)
			nbr_word++;
	return (nbr_word);
}

int copy_str_to_array(char **to_file, char const *str, int pos, char separator)
{
	int end_word = pos;
	int size_word = 0;

	while (str[end_word] != separator && str[end_word] != 0)
		end_word++;
	size_word = end_word - pos;
	(*to_file) = malloc(sizeof(char) * size_word + 1);
	for (int i = 0; i != size_word; i++)
		(*to_file)[i] = str[i + pos];
	(*to_file)[size_word] = 0;
	return (size_word);
}

char **str_to_array(char const *str, char separator)
{
	char **array = NULL;
	int a = 0;
	int i = 0;

	if (str == NULL || str[0] == 0)
		return (NULL);
	array = malloc(sizeof(char *) * (compt_str(str, separator) + 1));
	while (i <= (int)strlen(str)) {
		while (str[i] == separator && str[i] != 0)
			i++;
		if (str[i] != 0) {
			i += copy_str_to_array(&array[a], str, i, separator);
			a++;
		}
		i++;
	}
	array[a] = NULL;
	return (array);
}
