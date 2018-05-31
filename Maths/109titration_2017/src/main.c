/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of 109titration
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <zconf.h>
#include "my.h"

void malloc_tab(char ***board, int n)
{
	int i = 0;

	while (i != n + 1) {
		(*board)[i] = malloc(sizeof(char) * n);
		i++;
	}
}

void prepare_tab(char **tab, int n)
{
	char **board_x = malloc(sizeof(char *) * (n + 1));
	char **board_y = malloc(sizeof(char *) * (n + 1));
	char **y_s = malloc(sizeof(char *) * (n + 1));
	int i = 0;

	malloc_tab(&board_x, n);
	malloc_tab(&board_y, n);
	malloc_tab(&y_s, n);
	while (i != n) {
		put_in_board(tab, &board_x, &board_y, i);
		i++;
	}
	sort_number(&board_x, &board_y, n);
	do_the_programe(&board_x, &board_y, i, &y_s);
}

void do_titration(char *path)
{
	FILE *fp = fopen(path, "r");
	size_t len = 0;
	ssize_t read;
	char **tab = malloc(sizeof(char *) * 20);
	int n = 0;

	while ((read = getline(&tab[n], &len, fp)) != -1) {
		n++;
	}
	prepare_tab(tab, n);
	fclose(fp);
}

int check_error(int ac, char *file)
{
	int fd = open(file, O_RDONLY);

	if (ac != 2 || fd == -1)
		return (84);
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	if (check_error(ac, av[1]) == 84)
		return (84);
	do_titration(av[1]);
}
