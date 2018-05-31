/*
** EPITECH PROJECT, 2022
** CPE_tetris_2017
** File description:
** Created by tiflo,
*/
#include "tetris.h"

int fill_board(tetris_t *tetris)
{
	tetris->touch[5] = "q\0";
	tetris->touch[6] = " \0";
	tetris->x = map_x;
	tetris->y = map_y;
	return (0);
}

void malloc_map(char ***map, tetris_t tetris)
{
	int n = 0;

	(*map) = malloc(sizeof(char *) * tetris.y);
	while (n != tetris.y + 1) {
		(*map)[n] = malloc(sizeof(char) * tetris.x + 5);
		n++;
	}
}

int good_size_lenght(tetris_t tetris, char ***map, int n)
{
	int i = 1;

	(*map)[n][0] = '#';
	while (i != tetris.x - 1) {
		(*map)[n][i] = ' ';
		i++;
	}
	(*map)[n][i] = '#';
	return (0);
}

int create_map(char ***map, tetris_t tetris)
{
	int n = 0;

	malloc_map(map, tetris);
	enter_completed_line(map, tetris, n);
	n++;
	while (n != tetris.y - 1) {
		good_size_lenght(tetris, map, n);
		n++;
	}
	enter_completed_line(map, tetris, n);
	return (0);
}

int print_map(char ***map, tetris_t tetris)
{
	int n = 0;
	int y = tetris.y / 2;
	int lenght = my_strlen((*map)[0]);

	while (n != tetris.y + 1) {
		mvprintw(LINES / 2 - y, (COLS / 2) - (lenght / 2), (*map)[n]);
		printw("\n");
		n++;
		y--;
	}
	return (0);
}
