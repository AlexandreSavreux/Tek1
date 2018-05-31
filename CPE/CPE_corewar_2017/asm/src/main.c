/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "op.h"
#include "my.h"
#include "project.h"

int main(int ac, char **av)
{
	char *name = NULL;
	char *comment = NULL;
	FILE *fd;

	if (ac != 2)
		return (84);
	fd = fopen(av[1], "r");
	get_name_comment(fd, &name, &comment);
	if (name == NULL || comment == NULL)
		return (84);
	init_cor(name, comment, av[1]);
}
