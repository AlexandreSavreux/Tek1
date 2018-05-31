/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** Read a fill and return a str of this one
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "../lib/my/my.h"
#include "../lib/my/get_next_line.h"

char *read_fullfile(int fd)
{
	int size_max = READ_SIZE;
	char *text = malloc(sizeof(char) + 1);
	char *buffer = NULL;

	if (text == NULL)
		return (NULL);
	text[0] = '\0';
	while (size_max == READ_SIZE) {
		buffer = malloc(sizeof(char) * READ_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
		size_max = read(fd, buffer, READ_SIZE);
		if (size_max < 0)
			return (NULL);
		buffer[size_max] = '\0';
		text = my_strncat(text, buffer, my_strlen(buffer));
	}
	close(fd);
	return (text);
}
