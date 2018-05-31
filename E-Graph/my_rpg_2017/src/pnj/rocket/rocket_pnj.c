/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void manage_taliban_rocket_move(pnjs *pnj)
{
	sfVector2f pos = sfSprite_getPosition(pnj[TALIBAN].weapon[WEAPON].spr);

	if (sfSprite_getRotation(pnj[TALIBAN].weapon[WEAPON].spr) == 0.0) {
		pos.x += 6;
		sfSprite_setPosition(pnj[TALIBAN].weapon[WEAPON].spr, pos);
	}
	if (sfSprite_getRotation(pnj[TALIBAN].weapon[WEAPON].spr) == 180.0) {
		pos.x -= 6;
		sfSprite_setPosition(pnj[TALIBAN].weapon[WEAPON].spr, pos);
	}
}

void rocket_pnj_extension(elem *elem, sfIntRect rect)
{
	if (sfClock_getElapsedTime(
		elem->pnj[TALIBAN].weapon[WEAPON].clock).microseconds > 50000 &&
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfTrue) {
		if (rect.left < 160)
			rect.left += 80;
		else
			rect.left = 0;
		sfSprite_setTextureRect(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			rect);
		sfClock_restart(elem->pnj[TALIBAN].weapon[WEAPON].clock);
	}
}

void rocket_pnj_ext(elem *elem, sfVector2f pos, sfIntRect rect)
{
	if (manage_hitbox_taliban_rocket(elem) == 0) {
		rect.left = 0;
		elem->pnj[TALIBAN].weapon[BULLET].active = sfTrue;
		pos = sfSprite_getPosition(
			elem->pnj[TALIBAN].weapon[WEAPON].spr);
		pos.x -= 75;
		pos.y -= 75;
		sfSprite_setPosition(elem->pnj[TALIBAN].weapon[BULLET].spr,
			pos);
		elem->pnj[TALIBAN].weapon[WEAPON].active = sfFalse;
	}
	rocket_pnj_extension(elem, rect);
}

void rocket_pnj_extend(elem *elem, sfVector2f pos, sfIntRect rect)
{
	if (sfSprite_getScale(elem->pnj[TALIBAN].spr).x == -1 &&
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse) {
		sfSprite_setPosition(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			pos);
		sfSprite_setRotation(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			180.0);
		elem->pnj[TALIBAN].weapon[WEAPON].active = sfTrue;
		pos = sfSprite_getPosition(
			elem->pnj[TALIBAN].weapon[WEAPON].spr);
		pos.x -= 66;
		pos.y += 40;
		sfSprite_setPosition(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			pos);
	}
	manage_taliban_rocket_move(elem->pnj);
	rocket_pnj_ext(elem, pos, rect);
}

void rocket_pnj(sfSprite *pnj_spr, elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(pnj_spr);
	sfIntRect rect = sfSprite_getTextureRect(
		elem->pnj[TALIBAN].weapon[WEAPON].spr);

	pos.x += 24;
	pos.y += 30;
	if (sfSprite_getScale(elem->pnj[TALIBAN].spr).x == 1 &&
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse) {
		sfSprite_setPosition(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			pos);
		sfSprite_setRotation(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			0.0);
		elem->pnj[TALIBAN].weapon[WEAPON].active = sfTrue;
		pos = sfSprite_getPosition(
			elem->pnj[TALIBAN].weapon[WEAPON].spr);
		pos.x += 40;
		pos.y += 20;
		sfSprite_setPosition(elem->pnj[TALIBAN].weapon[WEAPON].spr,
			pos);
	}
	rocket_pnj_extend(elem, pos, rect);
}