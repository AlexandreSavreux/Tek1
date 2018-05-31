/*
** EPITECH PROJECT, 2022
** Main.c
** File description:
** Created by f.louvet,
*/
#include "struct.h"

int main(int ac, char **av)
{
	if (ac > 1) {
		if (av[1][0] == '-' && av[1][1] == 'h') {
			my_printf("Use ./my_hunter to play\n");
			my_printf("Use ./my_hunter god to be surprised\n");
			return (0);
		}
	} else
		return (run());
}