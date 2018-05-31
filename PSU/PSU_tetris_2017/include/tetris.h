/*
** EPITECH PROJECT, 2022
** CPE_tetris_2017
** File description:
** Created by tiflo,
*/
#ifndef TETRIS_H
# define TETRIS_H

#include <ncurses.h>
#include <stdio.h>
#include "my.h"

typedef struct tetrimino_s {
	int colour;
	int width;
	int height;
	char **piece;
} tetrimino_t;

typedef struct tetris_s {
	char *touch[10];
	int x;
	int y;
	tetrimino_t **piece;
	int nb;
} tetris_t;

extern const int map_x;

extern const int map_y;

int recup_touch(char *term, tetris_t *tetris);

void debug_mode(tetris_t tetris);

void display_good_touch(tetris_t tetris, int *n);

int do_game(tetris_t tetris, char ***map);

char *recup_from_env(char *wanted, char **env);

int my_opener(tetris_t *tetris);

int print_map(char ***map, tetris_t tetris);

int create_map(char ***map, tetris_t tetris);

int enter_completed_line(char ***map, tetris_t tetris, int n);

int good_size_lenght(tetris_t tetris, char ***map, int n);

void malloc_map(char ***map, tetris_t tetris);

int fill_board(tetris_t *tetris);

int do_malloc(tetris_t *tetris);

# endif //CPE_TETRIS_2017_TETRIS_H
