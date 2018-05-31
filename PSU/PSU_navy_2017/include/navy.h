/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#ifndef PSU_NAVY_2017_NAVY_H
#define PSU_NAVY_2017_NAVY_H

int my_glob;

typedef struct player_s {
	pid_t pid;
	char **pos;
	char **map;
	char **vs_map;
} player_t;

typedef struct pos_s {

	int x;
	int y;
	int x2;
	int y2;
} pos_t;

typedef struct alloc_s {
	char **array1;
	char *array2;
	int i;
	int fd;
} alloc_t;

int player1(player_t *player, char *str);

int player2(player_t *player, int pid, char *str);

int my_sender(int pid, int nb);

void make_vs_map(player_t *player, int x, int y);

char **analyse_map(char **str, char **map);

int victory(char **str);

int translate(player_t *player, char *s);

char *turn(void);

void my_map_drawer(player_t *player, int ennemy);

int check_hit(player_t *player, int x, int y);

void def_x(player_t *player, int x, int y);

int check_pos(char **pos);

void my_listener(void);

#endif //PSU_NAVY_2017_NAVY_H
