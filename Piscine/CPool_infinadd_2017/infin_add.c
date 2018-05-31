/*
** EPITECH PROJECT, 2017
** infin_add.c
** File description:
** Add two infinite strings
*/
#include <unistd.h>
#include <stdlib.h>
#include "include/my.h"

int char_to_int(char c)
{
	return(c - 48);
}

char int_to_char(int c)
{
	return(c + 48);
}

char *inf_add(char *s1, char *s2)
{
	int global_size = my_strlen(s1) > my_strlen(s2) ?
		my_strlen(s1) + 2 : my_strlen(s2) + 2;
	int *result = malloc(sizeof(char) * global_size);
	int decade = 0;
	int nb1;
	int nb2;

	for(int j = 0; j < global_size; j++) {
		nb1 = s1[my_strlen(s1) - global_size - j];
		nb2 = s2[my_strlen(s2) - global_size - j];
		if (nb1 + nb2 + decade > 10) {
			result[global_size - j] = int_to_char(nb1 + nb2 - 10);
			decade = 1;
		} else {
			result[global_size - j - 2] = int_to_char(nb1 + nb2 + decade - 10);
		}
	}
}

int main (int ac, char **av)
{
	if (ac < 3 || (my_str_isnum(av[1]) == 1 ||  my_str_isnum(av[2]) == 1)) {
		write (2, "Invalid input\n", 14);
		return (84);
	}
	else
		inf_add(av[1], av[2]);
	return (0);
}
