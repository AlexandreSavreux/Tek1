/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Bootstrap my_ls
*/
#include "my_ls.h"
#include "my.h"

int my_f(void)
{

	DIR *rep;
	struct dirent *file;

	rep = opendir(".");
	if (rep == NULL)
		exit(1);
	file = readdir(rep);
	if (file == NULL)
		exit(1);
	my_putstr(file->d_name);
	while ((file = readdir(rep)) != NULL)
	{
		if (file == NULL)
			exit(1);
		my_printf("%s  ",(file->d_name));
	}
	my_putchar('\n');
	return (0);
}

int my_a(void)
{
	DIR *rep;
	struct dirent *file;
	struct stat statbuf;

	rep = opendir(".");
	if (rep == NULL)
		exit(1);
	file = readdir(rep);
	if (file == NULL)
                exit(1);
	my_printf("%s ",(file->d_name));
	while ((file = readdir(rep)) != NULL)
	{
		if (file == NULL)
			exit(1);
		my_printf("%s ",file->d_name);
	}
        my_putchar('\n');
	return (0);
}

int my_ls()
{
	DIR *rep;
	struct dirent *file;

	rep = opendir(".");
	if (rep == NULL)
		exit(1);
	file = readdir(rep);
	if (file == NULL)
		exit(1);
	my_printf("%s ",(file->d_name));
	while ((file = readdir(rep)) != NULL)
	{
		if (file == NULL)
			exit(1);
		if (file->d_name[0] != '.')
		{
			my_printf("%s ",file->d_name);
		}
	}
	my_putchar('\n');
	return (0);
}

int my_parser1(int ac, char **av)
{
	if (ac == 1)
		my_ls();
	else if (ac == 2 && (av[1], "-a"))
		my_a();
	else if (ac == 2 && (av[1], "-f"))
		my_f();
	return (0);
}

int main(int ac, char **av)
{
	if (ac >= 1)
	{
		my_parser1(ac, av);
		return (0);
	}
	else
		return (1);
}
