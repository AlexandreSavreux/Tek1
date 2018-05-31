/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/
#include "my.h"
#include "stumper.h"

#include "my.h"
#include "stumper.h"

int free_and_quit(char **hash_tab, char **point_tab)
{
	write(1, "#\n", 2);
	free_array(hash_tab);
	free_array(point_tab);
	return (0);
}

int main(int ac, char **av)
{
	char **ret;
	char **hash_tab = my_str_to_word_array(av[2], '@', '@');
	char **point_tab = my_str_to_word_array(av[3], '@', '@');
	char **tmp;
	int time;

	if (error_handling_core(ac, av))
		return (84);
	time = my_getnbr(av[1]);
	if (time == -1)
		return (free_and_quit(hash_tab, point_tab));
	while (time-- != 0) {
		ret = modify_my_tab(hash_tab, point_tab, av[2], 0);
		tmp = modify_my_tab(hash_tab, point_tab, av[2], 0);
		point_tab = modify_my_tab(hash_tab, point_tab, av[3], 1);
		hash_tab = arrdup(tmp);
	}
	my_show_array(ret);
	return (0);
}
