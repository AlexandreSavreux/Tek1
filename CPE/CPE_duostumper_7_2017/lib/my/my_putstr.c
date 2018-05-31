/*
** EPITECH PROJECT, 2017
** my_putstr
** File description:
** my_putstr
*/

#include "my.h"

int my_putstr(char const *str)
{
	write(1, str, my_strlen(str));
}

int my_puterror(char const *str)
{
	write(2, str, my_strlen(str));
}