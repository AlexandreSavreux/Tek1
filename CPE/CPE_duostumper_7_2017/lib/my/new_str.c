/*
** EPITECH PROJECT, 2018
** new_str
** File description:
** new_str
*/

#include <stdlib.h>

char *new_str(int len)
{
	char *res = malloc(sizeof(char) * (len + 1));
	int i = 0;

	if (res == NULL)
		return (NULL);
	while (i != len) {
		res[i] = '\0';
		i++;
	}
	res[0] = '\0';
	return (res);
}