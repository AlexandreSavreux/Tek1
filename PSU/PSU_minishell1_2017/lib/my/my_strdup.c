/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include <stdlib.h>

char *my_strdup(const char *src)
{
	int i = 0;
	char *dest = NULL;

	while (src && src[i])
		i++;
	if (!(dest = malloc(sizeof(char) * i + 2)))
		return (NULL);
	i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}