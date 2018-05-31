/*
** EPITECH PROJECT, 2022
** CPE_BSQ_2017
** File description:
** Created by tiflo,
*/
#include "bsq.h"

int counter(int *map)
{
	int cpt = 0;

	while (map[cpt] != -1)
		cpt++;
	return (cpt);
}

void my_convert(int *map)
{
	int contain = counter(map);
	int size = counter(map) + 1;

	while (contain < bsq_t.size - 1) {
		if (map[contain] != -1 && map[contain] != 0 &&
			contain % (contain + 1) != 0)
			map[contain] = gen_algo(map, contain, size);
		contain = contain + 1;
	}
	parser(map);
}

int gen_algo(int *map, int in, int len)
{
	int res = map[in - 1];

	if (map[in - len] < res)
		res = map[in - len];
	if (map[in - len - 1] < res)
		res = map[in - len - 1];
	res++;
	return (res);
}

void main_algo(void)
{
	bsq_t.size = my_strlen(bsq_t.copy);
	int *tab = malloc(sizeof(int) * bsq_t.size);
	int inc = 0;

	while (inc != bsq_t.size) {
		if (bsq_t.copy[inc] == 'o')
			tab[inc] = 0;
		else if (bsq_t.copy[inc] == '.')
			tab[inc] = 1;
		else
			tab[inc] = -1;
		inc = inc + 1;
	}
	my_convert(tab);
	free(tab);
}