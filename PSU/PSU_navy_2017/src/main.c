/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_helper(void)
{
	my_putstr("USAGE:\n");
	my_putstr("	./navy [first_player_pid] navy_positions\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("	first_player_pid: only for the 2nd player. pid of");
	my_putstr(" the first player.\n");
	my_putstr(
		"     navy_positions: file representing the positions of the");
	my_putstr(" ships.\n");
	return (0);
}

int main(int ac, char **av)
{
	if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
		return (my_helper());
	if (check_errors(ac) == 84)
		return (84);
	return (link_start(ac, av));
}
