/*
** EPITECH PROJECT, 2018
** my_gest_error_gnl
** File description:
** my_gest_error_gnl
*/

#include <stdlib.h>

char *finish(char *ret)
{
	if (ret[0] == '\0')
		return (NULL);
	return (ret);
}

char *get_error(char buff[])
{
	buff[0] = '\0';
	return ("\n");
}