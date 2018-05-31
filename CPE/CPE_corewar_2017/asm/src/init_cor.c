/*
** EPITECH PROJECT, 2018
** init_cor
** File description:
** init_cor
*/

#include "op.h"
#include "my.h"
#include "project.h"

void convert_str(char *str, char modif[])
{
	int i = 0;

	while (str[i] != '\0') {
		modif[i] = str[i];
		i++;
	}
	modif[i] = '\0';
}

void get_pathname(char *path, char pathname[])
{
	int i = 0;

	while (path[i] != '.' && path[i] != '\0') {
		pathname[i] = path[i];
		i++;
	}
	pathname[i] = '.';
	pathname[i + 1] = 'c';
	pathname[i + 2] = 'o';
	pathname[i + 3] = 'r';
	pathname[i + 4] = '\0';
}

void init_cor(char *name, char *comment, char *path)
{
	int fd;
	struct header_s header = {.prog_name = "", .comment = ""};
	int i = COREWAR_EXEC_MAGIC;
	char pathname[my_strlen(path) + 2];

	get_pathname(path, pathname);
	fd = open(pathname, O_CREAT | O_WRONLY, 0644);
	i = ((i & 0x000000ff) << 24) | ((i & 0x0000ff00) << 8) |
		((i & 0x00ff0000) >> 8) | ((i & 0xff000000) >> 24);
	header.magic = i;
	header.prog_size = 0;
	convert_str(name, header.prog_name);
	convert_str(comment, header.comment);
	write(fd, &header, sizeof(header));
}
