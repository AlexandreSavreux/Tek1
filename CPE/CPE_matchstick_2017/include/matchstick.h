/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#ifndef MATCHSTICK_H
#define MATCHSTICK_H

typedef struct my_map_s {
	char *str;
	int my_max_stick;
	int size;
	int line;
	int *map;
	int *backup;
	int stick;
	int max_stick;
	int victory;
	int status;
} my_map_t;

#endif //MATCHSTICK_H
