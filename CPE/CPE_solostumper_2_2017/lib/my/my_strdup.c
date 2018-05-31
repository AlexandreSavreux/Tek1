/*
** EPITECH PROJECT, 2022
** CPE_solostumper_2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

char *my_strdup(const char *src)
{
	int i = 0;
	char *dest;

	while (src && src[i])
		i++;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}