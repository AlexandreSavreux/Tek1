/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** do the main function
*/
#include "my.h"

int main(int ac, char **av, char **env)
{
	int my_return = args_main_handler(ac, av);

	if (env_handler(env) == 8)
		return (84);
	if (my_return != 0)
		return (my_return);
	return (do_game());
}
