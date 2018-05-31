/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void *my_memset(void *str, int c, size_t n)
{
	char *tmp = str;

	while (n > 0) {
		*tmp++ = c;
		n--;
	}
	return (str);
}