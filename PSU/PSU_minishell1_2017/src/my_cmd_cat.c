/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** Assemble deux strings
*/
#include "my.h"

char *my_cmd_cat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;
	char *str3 = malloc(
		sizeof(char) * (my_strlen(dest) + my_strlen(src) + 2));

	if (str3 == NULL)
		return (NULL);
	for (; dest[i] != '\0'; i++)
		str3[i] = dest[i];
	str3[i++] = '/';
	while (src[j] != '\0')
		str3[i++] = src[j++];
	str3[i] = '\0';
	return (str3);
}
