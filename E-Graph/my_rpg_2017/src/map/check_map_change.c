/*
** EPITECH PROJECT, 2018
** check_map_change
** File description:
** checks if the player switches room
*/

#include "map.h"

void change_room(elem *elem, sfVector2f pos, map room)
{
	sfIntRect rect = sfSprite_getTextureRect(
		elem->inv.user.item[ROCKET].weapon[BULLET].spr);

	rect.left = 0;
	sfSprite_setTextureRect
		(elem->inv.user.item[ROCKET].weapon[BULLET].spr, rect);
	elem->room = room;
	sfSprite_setPosition(elem->chicken, pos);
	elem->inv.user.item[ROCKET].weapon[WEAPON].active = sfFalse;
	elem->inv.user.item[ROCKET].weapon[BULLET].active = sfFalse;
	elem->pnj[TALIBAN].weapon[WEAPON].active = sfFalse;
	elem->pnj[TALIBAN].weapon[BULLET].active = sfFalse;
}

void check_map_change(elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(elem->chicken);

	(*change_map[elem->room])(elem, pos);
}
