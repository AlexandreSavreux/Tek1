/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by tiflo,
*/
#include "bsq.h"

void parser(int *map)
{
	int pos = 0;
	int size = 0;
	int height = 0;
	int width = 0;
	int pos_save = 0;
	int cpt = 1;

	finder(&pos, &size, map);
	pos_save = pos;
	height = size;
	width = size;
	while (height != 0) {
		observer_block(map, width, pos);
		pos = pos_save - ((counter(map) + 1) * cpt);
		height--;
		cpt++;
	}
	my_putstr(bsq_t.copy);
}

void observer_block(int *map, int width, int pos)
{
	while (width != 0) {
		if (map[pos] == -1)
			pos--;
		bsq_t.copy[pos] = 'x';
		pos--;
		width--;
	}
}

void finder(int *pos, int *size, int *map)
{
	int imp = 0;
	int res = 0;
	int neg_nbr = -1;

	while (imp != bsq_t.size) {
		if (map[imp] == -1)
			neg_nbr = neg_nbr + 1;
		if (res < map[imp]) {
			res = map[imp];
			*pos = imp;
		}
		imp++;
	}
	*size = res;
}