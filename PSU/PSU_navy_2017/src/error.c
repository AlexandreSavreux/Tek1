/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int check_errors(int ac)
{
	if (ac < 2 || ac > 3) {
		my_puterror("Invalid number of arguments\n");
		return (84);
	}
	return (0);
}