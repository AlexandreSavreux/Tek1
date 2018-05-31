/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by f.louvet,
*/
#ifndef BSQ_H
#define BSQ_H

#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

struct bsq_s {
	char *map;
	char *copy;
	int size;
} bsq_t;

void parser(int *map);

void observer_block(int *map, int width, int xy);

void finder(int *xy, int *size, int *map);

int counter(int *map);

void my_convert(int *map);

int gen_algo(int *map, int in, int len);

void create_map(int fd, char *file);

void main_algo(void);

#endif //BSQ_H
