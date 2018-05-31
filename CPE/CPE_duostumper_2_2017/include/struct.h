/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct setting_s {
	int width;
	int height;
	char name_p1;
	char name_p2;
	char finish;
} setting_t;

int core_optns(char **av, setting_t *settings);

int change_width(int value, setting_t *settings);

int change_height(int value, setting_t *settings);

int change_players_avatar(char *optn, char *value, setting_t *settings);

int change_referee(char *value, setting_t *settings);

int game_loop(setting_t *settings);

#endif
