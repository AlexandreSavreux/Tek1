/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

int check_time_chicken_ak(damage *damage)
{
	if (sfClock_getElapsedTime(damage->clock_ak).microseconds > 150000) {
		sfClock_restart(damage->clock_ak);
		return (0);
	}
	return (1);
}

void chicken_life_ext(elem *elem, sfVector2f pos, sfVector2f pos_e)
{
	if ((pos.y >= pos_e.y && pos.y <= pos_e.y + 150) ||
		(pos.y + 72 >= pos_e.y && pos.y + 72 <= pos_e.y + 150)) {
		if (check_time_rocket(&elem->pnj[TALIBAN].damage) &&
			elem->pnj[TALIBAN].weapon[BULLET].active == sfTrue)
			elem->stats.life -= 100;
	}
}

void chicken_life(elem *elem)
{
	sfVector2f pos_c = sfSprite_getPosition(
		elem->pnj[TALIBAN].weapon[BULLET].spr);
	sfVector2f pos = sfSprite_getPosition(elem->chicken);

	if (sfSprite_getTextureRect(elem->pnj[TERRORIST].spr).top == 123) {
		if (!check_time_chicken_ak(&elem->damage))
			elem->stats.life -= 25;
	}
	if ((pos.x >= pos_c.x && pos.x <= pos_c.x + 150) ||
		(pos.x + 72 >= pos_c.x && pos.x + 72 <= pos_c.x + 150))
		chicken_life_ext(elem, pos, pos_c);
	if (elem->stats.life <= 0)
		elem->game = sfFalse;
}
