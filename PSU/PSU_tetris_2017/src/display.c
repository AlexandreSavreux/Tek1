/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include "tetris.h"

int enter_completed_line(char ***map, tetris_t tetris, int n)
{
	int i = 0;

	while (i != tetris.x) {
		(*map)[n][i] = '#';
		i++;
	}
	return (0);
}

int do_game(tetris_t tetris, char ***map)
{
	int action = 0;

	initscr();
	while (action != tetris.touch[5][0]) {
		refresh();
		print_map(map, tetris);
		action = getch();
		clear();
	}
	endwin();
	return (0);
}

void display_good_touch(tetris_t tetris, int *n)
{
	int i = 0;

	if (tetris.touch[*n][0] == '\E' && tetris.touch[*n][1] == 'O' &&
		tetris.touch[*n][2] == 'D') {
		my_putstr("^EOD\n");
		i = 1;
	}
	if (tetris.touch[*n][0] == '\E' && tetris.touch[*n][1] == 'O' &&
		tetris.touch[*n][2] == 'C') {
		i = 1;
		my_putstr("^EOC\n");
	}
	if (tetris.touch[*n][0] == '\E' && tetris.touch[*n][1] == 'O' &&
		tetris.touch[*n][2] == 'A') {
		i = 1;
		my_putstr("^EOA\n");
	}
	if (tetris.touch[*n][0] == '\E' && tetris.touch[*n][1] == 'O' &&
		tetris.touch[*n][2] == 'B') {
		my_putstr("^EOB\n");
		i = 1;
	}
	if (tetris.touch[*n][0] == ' ') {
		my_putstr("(space)\n");
		i = 1;
	}
	if (i != 1) {
		my_putstr(tetris.touch[*n]);
		my_putchar('\n');
	}
	(*n)++;
}

void debug_mode(tetris_t tetris)
{
	int n = 1;

	my_putstr("*** DEBUG MODE ***\n");
	my_putstr("Key Left : ");
	display_good_touch(tetris, &n);
	my_putstr("Key Right : ");
	display_good_touch(tetris, &n);
	my_putstr("Key Turn : ");
	display_good_touch(tetris, &n);
	my_putstr("Key Drop : ");
	display_good_touch(tetris, &n);
	my_putstr("Key Quit : ");
	display_good_touch(tetris, &n);
	my_putstr("Key Pause : ");
	display_good_touch(tetris, &n);
	my_putstr("Next : yes\n");
	my_putstr("Level : 1\n");
	my_printf("Size : %d*%d\n", tetris.x, tetris.y);
}
