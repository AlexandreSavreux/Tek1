/*
** EPITECH PROJECT, 2018
** my_strnldup
** File description:
** my_strnldup
*/

#include "my.h"
#include <stdlib.h>

char *my_strnldup(char *str, int skip)
{
	char *tmp = malloc(sizeof(char) * (my_strlen(str) - skip + 2));
	int i = skip - 1;
	int j = 0;

	while (str[i] != '\0') {
		tmp[j] = str[i];
		i++;
		j++;
	}
	tmp[j] = '\0';
	return (tmp);
}
