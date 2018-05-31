/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strncat(char *dest, char const *str, int nb)
{
	int dest_len = my_strlen(dest);
	int i;

	for (i = 0, i < nb && str[i] != '\0' ; i++ ;)
		dest[dest_len + i] = str[i];
	dest[dest_len + i] = '\0';
	return (dest);
}
