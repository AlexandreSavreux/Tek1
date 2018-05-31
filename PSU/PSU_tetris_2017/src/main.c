/*
** EPITECH PROJECT, 2022
** CPE_tetris_2017
** File description:
** Created by tiflo,
*/
#include "tetris.h"

const int map_x = 30;

const int map_y = 20;

int main(int ac, char **av, char **env)
{
	tetris_t tetris;
	char **map;
	char *term;

	term = recup_from_env("TERM=", env);
	recup_touch(term, &tetris);
	my_opener(&tetris);
	fill_board(&tetris);
	create_map(&map, tetris);
	debug_mode(tetris);
	do_game(tetris, &map);
}
