/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by f.louvet,
*/
#include "bsq.h"

void create_map(int fd, char *file)
{
	long long int area = 0;
	struct stat *buffer = malloc(sizeof(struct stat));;
	bsq_t.map = NULL;
	bsq_t.copy = NULL;

	if (stat(file, buffer) == -1)
		exit(84);
	area = (long long)buffer->st_size;
	bsq_t.map = malloc(sizeof(char) * area + 1);
	if (read(fd, bsq_t.map, area) == -1)
		exit(84);
	bsq_t.map[area] = '\0';
	bsq_t.copy = bsq_t.map;
	while (*bsq_t.copy != '.' && *bsq_t.copy != 'o')
		bsq_t.copy = bsq_t.copy + 1;
	main_algo();
	free(bsq_t.map);
	free(buffer);
}

int main(int ac, char **av)
{
	int fd = 0;

	if (ac != 2)
		return (84);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (84);
	create_map(fd, av[1]);
	if (close(fd) == -1)
		return (84);
	return (0);
}