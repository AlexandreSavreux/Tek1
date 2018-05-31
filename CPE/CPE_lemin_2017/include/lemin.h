/*
** EPITECH PROJECT, 2022
** CPE_lemin_2017
** File description:
** Created by tiflo,
*/
#ifndef CPE_LEMIN_2017_LEMIN_H
#define CPE_LEMIN_2017_LEMIN_H

#define TUNNEL_SEP '-'

/*typedef struct s_room {
	int *dest;
	int nb_links;
	int ant;
	char *name;
} room_t;

typedef struct s_graph {
	int nb_room;
	room_t *rooms;
} graph_t;

typedef struct s_lem {
	char **map;
	int nb_ants;
	int start;
	int end;
	graph_t graph;
	} lem_t;*/

typedef enum command_s {
	START,
	END,
	PATH,
} command_t;

typedef struct room_s {
	int ant;
	enum command_s cmd;
	char *name;
	int x;
	int y;
	struct room_s **next;
} room_t;

int check_str(char *str);

int my_openner(room_t *anthil);

int args_checker(int ac, char **av);

#endif //CPE_LEMIN_2017_LEMIN_H
