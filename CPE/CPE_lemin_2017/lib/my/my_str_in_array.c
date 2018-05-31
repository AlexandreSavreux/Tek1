/*
** EPITECH PROJECT, 2022
** CPE_lemin_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_str_in_tab(char **array, char *str)
{
	int i = -1;
	int nb_str = 0;

	while (array[++i] != NULL)
		if (my_strstr(array[i], str) == 0)
			++nb_str;
	if (nb_str == 0)
		my_printf("Error : %s line missing.\n", str);
	else if (nb_str != 1)
		my_printf("Error : %s multiple definitions.\n", str);
	return (nb_str);
}