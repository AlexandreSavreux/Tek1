/*
** EPITECH PROJECT, 2017
** 101pong.c
** File description:
** manages arguments errors
*/

#include <unistd.h>
#include <stdlib.h>
#include "my.h"

int my_numisvalid(char *nb)
{
	int i = 0;
	int points = 0;

	if (nb[0] == '-' || nb[0] == '+') {
		i++;
		if (nb[1] == '.')
			return (1);
	}
	if (nb[0] == '.' || nb[my_strlen(nb) - 1] == '.')
		return (1);
	while (nb[i] != '\0') {
		if (nb[i] != '.' && (nb[i] < '0' || nb[i] > '9'))
			return (1);
		if (nb[i] == '.')
			points++;
		i++;
	}
	if (points > 1)
		return (1);
	return (0);
}

int check_time(char *nb)
{
	int i = 0;

	if (my_numisvalid(nb) == 1)
		return (1);
	while (nb[i] != '\0' && nb[i] != '.')
		i++;
	while (nb[i] != '\0') {
		if (nb[i] != '0' && nb[i] != '.')
			return (1);
		i++;
	}
	if (char_to_int(nb) < 0)
		return (1);
	return (0);
}

int check_arguments(int ac, char **av)
{
	int i = 1;

	if (ac != 8) {
		write(2, "Invalid number of arguments\n", 28);
		exit(84);
	}
	while (i < 7) {
		if (my_numisvalid(av[i]) == 1) {
			write(2, "Invalid argument(s)\n", 20);
			exit(84);
		}
		i++;
	}
	if (check_time(av[7]) == 1) {
		write(2, "Invalid time\n", 13);
		exit(84);
	}
	return (0);
}
