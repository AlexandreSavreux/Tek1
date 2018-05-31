/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"

char *my_strcat(char *dest, char const *str)
{
	int dest_len = my_strlen(dest);
	int i;

	for (i = 0, str[i] != '\0'; i++;)
		dest[dest_len + i - 1] = str[i];
	dest[dest_len + i] = '\0';
	return (dest);
}