/*
** EPITECH PROJECT, 2017
** ginger.h
** File description:
** ginger.h
*/

#ifndef GINGER_H_
	#define GINGER_H

typedef struct ginger_s {
	int moves;
	int y;
	int x;
	char *map_name;
} ginger_t;

char **get_my_file(char *);

ginger_t init_ginger(char **av);


#endif