/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/

#include "struct.h"
//#include "game.h"
#include "my.h"

static void init_struct(setting_t *settings)
{
	settings->width = 7;
	settings->height = 6;
	settings->name_p1 = 'X';
	settings->name_p2 = 'O';
	settings->finish = '#';
}

int main(int ac, char **av)
{
	setting_t settings;

	init_struct(&settings);
	if (ac > 1)
		if (core_optns(av, &settings))
			return (84);
	return (0);
}
