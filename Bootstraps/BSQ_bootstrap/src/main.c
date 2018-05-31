/*
** EPITECH PROJECT, 2017
** BSQ.c
** File description:
** main functions for BSQ
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my_pushswap.h"

int main(int ac, char **av)
{
	int fd = open(av[1], O_RDONLY);
	if (fd == -1) {
		write(1, "FAILURE\n", 8);
		my_put_nbr(fd);
		return (1);
	}
	else if (fd >= 0) {
		write(1, "SUCCESS\n", 8);
		my_put_nbr(fd);
	}
	return (0);
}
