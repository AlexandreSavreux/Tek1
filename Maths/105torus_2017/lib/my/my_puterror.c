/*
** EPITECH PROJECT, 2022
** 104intersection_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_puterror(char const *str, int quit)
{
	write(2, str, my_strlen(str));
	if (quit == 1)
		exit(84);
}