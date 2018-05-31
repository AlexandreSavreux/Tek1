/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** Display one by one the characters of a string
*/
#include "my.h"

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
	return (0);
}
