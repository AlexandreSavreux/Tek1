/*
** EPITECH PROJECT, 2022
** CPE_getnextline_2017
** File description:
** Created by tiflo,
*/
#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

int main(int ac, char **av)
{
	int fd = 0;
	char *str;

	if (ac == 1)
		while ((str = get_next_line(fd)) != NULL)
			printf("%s\n", str);
	if (ac == 2) {
		fd = open(av[1], O_RDONLY);
		if ((str = get_next_line(fd)) != NULL)
			printf("%s\n", str);
	}
	if (ac == 3) {
		str = get_next_line(fd);
		printf("%s\n", str);
	}
}