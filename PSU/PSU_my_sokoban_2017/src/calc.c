/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by f.louvet,
*/
#include "sokoban.h"

int get_player_pos(char *map)
{
	for (int i = 0; i < my_strlen(map); i++) {
		if (map[i] == 'P') {
			return (i);
		}
	}
	return (-1);
}

int *map_size(char *map)
{
	int *size = malloc(sizeof(int) * 2);
	int width = 0;
	int height = 0;

	while (map[width] != '\n') {
		width++;
	}
	height = my_strlen(map) / (width + 1);
	size[0] = width;
	size[1] = height;
	return (size);
}

void check_validity(char *map)
{
	int nb_p = 0;
	int nb_box = 0;
	int nb_target = 0;
	int i = 0;

	while (map[i] != '\0') {
		if (map[i] == 'P')
			nb_p++;
		if (map[i] == 'X')
			nb_box++;
		if (map[i] == 'O')
			nb_target++;
		i++;
	}
	check_map(nb_p, nb_box, nb_target);
}

char *create_map(char *filename)
{
	int fd;
	char temp[2];
	char *buffer;
	int size = 0;

	fd = open(filename, O_RDONLY);
	while (read(fd, temp, 1)) {
		size++;
	}
	close(fd);
	buffer = malloc(sizeof(char) * size + 1);
	if (buffer == NULL)
		exit(84);
	fd = open(filename, O_RDONLY);
	read(fd, buffer, size);
	buffer[size] = '\0';
	close(fd);
	return (buffer);
}

char *make_map(char *filename)
{
	char *map;

	map = create_map(filename);
	check_validity(map);
	return (map);
}