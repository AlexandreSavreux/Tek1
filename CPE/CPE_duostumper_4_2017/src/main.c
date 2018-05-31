/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <database.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include "my.h"

char **get_fullfile(char *file_name)
{
	size_t size = 0;
	char *buffer = NULL;
	FILE *fd = fopen(file_name, "r");
	int i = 0;
	char **arr = calloc(1, sizeof(char *));

	if (fd == NULL)
		return (NULL);
	while (getline(&buffer, &size, fd) != -1) {
		if (buffer[strlen(buffer) - 1] == '\n')
			buffer[strlen(buffer) - 1] = '\0';
		arr[i] = strdup(buffer);
		arr = reallocarray(arr, 1, sizeof(char *) * (i + 2));
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

int main(int ac, char **av)
{
	char **list = get_fullfile(av[1]);
	database_t *info;

	if (ac == 1)
		return (84);
	if (list == NULL) {
		printf("yolo\n");
		return (84);
	}
	info = get_info(list);
	return (0);
}
