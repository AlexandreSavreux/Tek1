/*
** EPITECH PROJECT, 2022
** CPE_tetris_2017
** File description:
** Created by tiflo,
*/
#include <dirent.h>
#include <fcntl.h>
#include <get_next_line.h>
#include "tetris.h"

static int my_precheck(char *path, tetris_t *tetris)
{
	int fd = open(path, O_RDONLY);
	char **params;

	if (fd != -1) {
		params = my_str_to_wordarray(get_next_line(fd), ' ');
		tetris->nb++;
	}
	return (0);
}

int my_opener(tetris_t *tetris)
{
	DIR *rep;
	struct dirent *file;
	char path[269] = "";

	rep = opendir("./tetriminos");
	if (rep == NULL)
		return (1);
	while ((file = readdir(rep)) != NULL) {
		if (file == NULL)
			return (1);
		if (file->d_name[0] != '.') {
			my_strcat(path, "./tetriminos/");
			my_strcat(path, file->d_name);
			my_precheck(path, tetris);
			path[0] = '\0';
		}
	}
	closedir(rep);
	return (0);
}
