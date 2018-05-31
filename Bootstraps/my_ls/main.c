/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Bootstrap my_ls
*/
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int main (int ac, char **av)
{
	struct stat lalala;

	stat(av[1], &lalala);
	my_putstr(av[1]);
	my_putstr("Is coming");
	my_put_nbr(lalala.st_size);
	return (0);
}
