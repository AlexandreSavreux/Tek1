/*
** EPITECH PROJECT, 2017
** my_strdup
** File description:
** my_strdup
*/

#include "my.h"

char *my_strdup(char const *src)
{
	char *str;
	int i = my_strlen(src);
	int y = 0;

	str = malloc(sizeof(char) * (i + 1));
	while (src[y] != '\0') {
		str[y] = src[y];
		y++;
	}
	str[y] = '\0';
	return (str);
}