/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by tiflo,
*/
#ifndef SOKOBAN_H
#define SOKOBAN_H

#include <stdlib.h>
#include <fcntl.h>
#include "my.h"

struct data_s {
	int goal;
} data_t;

void check_args(int ac, char **av);

void check_ifmap(char *name);

char *make_map(char *filename);

char *create_map(char *filename);

void check_validity(char *map);

void check_map(int nb_p, int nb_box, int nb_target);

int my_sokoban(char *map, char *copy);

int score_win(char *map);

void move_box(char *map, int player, int box_position, int offset);

int player_move_it(int *player_pos, char *map, int mouvement, char *backup_map);

int valid_move(int *player_pos, char *map, int mouvement, char *backup_map);

int check_size(int lines, int cols, char *map);

int check_score(char *map, char *backup_map);

int get_player_pos(char *map);

int player_move(int move, int score, char *map, char *backup_map);

int game_logic(char *map, char *backup_map, int score, int play);

int *map_size(char *map);

#endif //SOKOBAN_H
