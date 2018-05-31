/*
** EPITECH PROJECT, 2022
** CPE_lemin_2017
** File description:
** Created by tiflo,
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

static int my_strcmp(char *dest, char *str)
{
	int i = 0;

	for (i = 0; str[i] != '\0'; i++) {
		if (str[i] != dest[i])
			return (1);
	}
	if (dest[i] == '\0')
		return (0);
	return (1);
}

int display_help(void)
{
	char buffer[267];
	int fd = open("assets/usage", O_RDONLY);

	if (fd == -1)
		return (84);
	read(fd, buffer, 267);
	write(1, buffer, 267);
	close(fd);
	return (0);
}

int my_opts(char **av)
{
	if (my_strcmp("--debug", av[1]) == 0)
		return (42);
	if (my_strcmp("-h", av[1]) == 0) {
		display_help();
		return (43);
	}
}

int args_checker(int ac, char **av)
{
	if (my_opts(av) == 43)
		return (6);
	if (my_opts(av) == 42)
		return (42);
	return (84);
}
