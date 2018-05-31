/*
** EPITECH PROJECT, 2017
** my_strcpy
** File description:
** my_strcpy
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	dest = my_strdup(src);
	return (dest);
}
