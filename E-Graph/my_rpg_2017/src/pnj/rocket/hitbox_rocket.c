/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void do_taliban_explosion(pnjs *pnj)
{
	sfIntRect rect = sfSprite_getTextureRect(
		pnj[TALIBAN].weapon[BULLET].spr);

	if (sfSprite_getTextureRect(pnj[TALIBAN].weapon[BULLET].spr).left ==
		750) {
		pnj[TALIBAN].weapon[BULLET].active = sfFalse;
		rect.left = 0;
	} else if (sfClock_getElapsedTime(
		pnj[TALIBAN].weapon[BULLET].clock).microseconds > 50000) {
		rect.left += 150;
		sfClock_restart(pnj[TALIBAN].weapon[BULLET].clock);
	}
	sfSprite_setTextureRect(pnj[TALIBAN].weapon[BULLET].spr, rect);
}

void change_hitbox_taliban_rocket(float rotation, sfIntRect *rect)
{
	if (rotation == 180.0) {
		rect->width = -80;
		rect->height = -21;
	}
}

int manage_hitbox_taliban_rocket_extend(elem *elem)
{
	sfVector2f pos_c = sfSprite_getPosition(elem->chicken);
	sfVector2f pos = sfSprite_getPosition(
		elem->pnj[TALIBAN].weapon[WEAPON].spr);

	if ((pos.y >= pos_c.y && pos.y <= pos_c.y + 72) ||
		(pos.y + 21 >= pos_c.y && pos.y + 21 <= pos_c.y + 72)) {
		if ((pos.x >= pos_c.x + 72 && pos.x <= pos_c.x + 144) ||
			(pos.x + 80 >= pos_c.x + 72 &&
				pos.x + 80 <= pos_c.x + 144))
			return (0);
	}
	return (1);
}

int manage_hitbox_taliban_rocket_ext(elem *elem, float rotation)
{
	sfVector2f pos_c = sfSprite_getPosition(elem->chicken);
	sfVector2f pos = sfSprite_getPosition(
		elem->pnj[TALIBAN].weapon[WEAPON].spr);

	if (rotation == 0.0) {
		if (!manage_hitbox_taliban_rocket_extend(elem))
			return (0);
		return (1);
	}
	if ((pos.y >= pos_c.y && pos.y <= pos_c.y + 72) ||
		(pos.y + 21 >= pos_c.y && pos.y + 21 <= pos_c.y + 72)) {
		if ((pos.x >= pos_c.x && pos.x <= pos_c.x + 72) ||
			(pos.x + 80 >= pos_c.x && pos.x + 80 <= pos_c.x + 72))
			return (0);
	}
	return (1);
}

int manage_hitbox_taliban_rocket(elem *elem)
{
	int i = 0;
	sfVector2f pos = sfSprite_getPosition(
		elem->pnj[TALIBAN].weapon[WEAPON].spr);
	sfIntRect rect = {pos.x, pos.y, 80, 21};
	float rotation = sfSprite_getRotation(
		elem->pnj[TALIBAN].weapon[WEAPON].spr);

	change_hitbox_taliban_rocket(rotation, &rect);
	while (i < elem->map[elem->room].nb_blocks) {
		if (sfIntRect_intersects(&rect, &elem->map[elem->room].block[i],
			NULL) == sfTrue)
			return (0);
		i++;
	}
	if (!manage_hitbox_taliban_rocket_ext(elem, rotation))
		return (0);
	if (pos.x < 0 || pos.x > 1920)
		return (0);
	if (pos.y < 0 || pos.y > 1080)
		return (0);
	return (1);
}