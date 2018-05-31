/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** Detects if there is a number
*/
#include "my.h"

int my_str_isnum(char const *str)
{
	int i = 0;

	if (str == NULL)
		return (1);
	if (str[i] == '-')
		i++;
	while (str[i] != '\0') {
		if ((str[i] >= '0' && str[i] <= '9')) {
			i++;
		} else
			return (0);
	}
	return (1);
}