/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** my_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (50);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}