/*
** EPITECH PROJECT, 2017
** my_revstr
** File description:
** reverses a character string
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
	int i;
	int e = 1;
	char j;

	for (i = 0; i < my_strlen(str) / 2; i++) {
		j = str[i];
		str[i] = str[my_strlen(str) - e];
		str[my_strlen(str) - e] = j;
		e++;
	}
	return (str);
}
