/*
** EPITECH PROJECT, 2022
** 104intersection_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_puterror(char const *str)
{
	write(2, str, my_strlen(str));
	return (0);
}