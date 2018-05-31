/*
** EPITECH PROJECT, 2018
** create_map
** File description:
** creates map
*/

#include <stdlib.h>
#include "rects.h"
#include "my.h"

void fill(const sfIntRect *blocks, room *map)
{
	int i = 0;

	while (i < map->nb_blocks) {
		map->block[i] = blocks[i];
		i++;
	}
}

void fill_blocks(room *map)
{
	const sfIntRect *rect[] = {SPAWN_BLOCKS, KITCHEN_BLOCKS,
				WAREHOUSE_BLOCKS, CAFET_BLOCKS, HALL_BLOCKS};

	for (int i = 0; i < NB_ROOMS; i++)
		fill(rect[i], &map[i]);
}

int set_blocks(elem *elem, int i)
{
	elem->map[i].sprite = sfSprite_create();
	sfSprite_setTexture
		(elem->map[i].sprite, elem->map[i].texture, sfTrue);
	sfSprite_setPosition(elem->map[i].sprite, POS[i]);
	elem->map[i].nb_blocks = NB_BLOCKS[i];
	elem->map[i].block = malloc
		(sizeof(sfIntRect) * elem->map[i].nb_blocks);
	if (!elem->map[i].block)
		return (0);
	return (1);
}

int create_maps(elem *elem)
{
	int i = 0;

	while (i < NB_ROOMS) {
		elem->map[i].texture = sfTexture_createFromFile
			(ROOM_TEXTURES[i], NULL);
		if (!elem->map[i].texture)
			return (0);
		if (!set_blocks(elem, i))
			return (0);
		i++;
	}
	fill_blocks(elem->map);
	return (1);
}
