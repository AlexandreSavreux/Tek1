/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

int check_pnj_hitbox(elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(
		elem->inv.user.item[ROCKET].weapon[WEAPON].spr);
	sfVector2f pos_ta = sfSprite_getPosition(elem->pnj[TERRORIST].spr);
	sfVector2f pos_t = sfSprite_getPosition(elem->pnj[TALIBAN].spr);

	if ((pos.x >= pos_t.x && pos.x <= pos_t.x + 68) ||
		(pos_t.x + 68 >= pos.x && pos_t.x + 68 <= pos.x + 80)) {
		if ((pos.y >= pos_t.y && pos.y <= pos_t.y + 123) ||
			(pos.y + 10 >= pos_t.y && pos.y + 10 <= pos_t.y + 123))
			return (0);
	}
	if ((pos.x >= pos_ta.x && pos.x <= pos_ta.x + 68) ||
		(pos_ta.x + 68 >= pos.x && pos_ta.x + 68 <= pos.x + 80)) {
		if ((pos.y >= pos_ta.y && pos.y <= pos_ta.y + 123) ||
			(pos.y + 10 >= pos_ta.y && pos.y + 10 <= pos_ta.y + 123))
			return (0);
	}
	return (1);
}