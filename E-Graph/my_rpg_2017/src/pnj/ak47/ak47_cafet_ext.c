/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

static void ak47_pnj_extend(pnjs *pnj, sfVector2f pos, sfIntRect rect)
{
	if (sfSprite_getScale(pnj[TERRORIST].spr).x == -1) {
		sfSprite_setRotation(pnj[TERRORIST].weapon[WEAPON].spr, 270.0);
		pnj[TERRORIST].weapon[WEAPON].active = sfTrue;
		pos = sfSprite_getPosition(pnj[TERRORIST].weapon[WEAPON].spr);
		pos.x -= 138;
		pos.y += 42;
		sfSprite_setPosition(pnj[TERRORIST].weapon[WEAPON].spr, pos);
	}
	if (sfClock_getElapsedTime(
		pnj[TERRORIST].weapon[WEAPON].clock).microseconds > 100000 &&
		pnj[TERRORIST].weapon[WEAPON].active == sfTrue) {
		if (rect.left < 92)
			rect.left += 46;
		else
			rect.left = 0;
		sfSprite_setTextureRect(pnj[TERRORIST].weapon[WEAPON].spr,
			rect);
		sfClock_restart(pnj[TERRORIST].weapon[WEAPON].clock);
	}
}

void ak47_pnj_cafet(sfSprite *pnj_spr, pnjs *pnj)
{
	sfVector2f pos = sfSprite_getPosition(pnj_spr);
	sfIntRect rect = sfSprite_getTextureRect(
		pnj[TERRORIST].weapon[WEAPON].spr);

	pos.x += 24;
	pos.y += 30;
	sfSprite_setPosition(pnj[TERRORIST].weapon[WEAPON].spr, pos);
	if (sfSprite_getScale(pnj[TERRORIST].spr).x == 1) {
		sfSprite_setRotation(pnj[TERRORIST].weapon[WEAPON].spr, 90.0);
		pnj[TERRORIST].weapon[WEAPON].active = sfTrue;
		pos = sfSprite_getPosition(pnj[TERRORIST].weapon[WEAPON].spr);
		pos.x += 86;
		pos.y += 0;
		sfSprite_setPosition(pnj[TERRORIST].weapon[WEAPON].spr, pos);
	}
	ak47_pnj_extend(pnj, pos, rect);
}

void manage_attack_pnj_cafet(pnjs *pnj)
{
	sfIntRect rect = sfSprite_getTextureRect(pnj[TERRORIST].spr);

	rect.top = 123;
	if (sfClock_getElapsedTime(pnj[TERRORIST].clock).microseconds > 80000 &&
		pnj[TERRORIST].hp[CAFET] > 0) {
		if (rect.left < 325)
			rect.left += 65;
		else
			rect.left = 0;
		sfClock_restart(pnj[TERRORIST].clock);
	}
	sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
}

void manage_hp_rect_cafet(pnjs *pnj)
{
	sfIntRect rect = {0, 0, 80, 20};

	if (pnj[TERRORIST].hp[CAFET] == 75)
		rect.left = 80;
	if (pnj[TERRORIST].hp[CAFET] == 50)
		rect.left = 160;
	if (pnj[TERRORIST].hp[CAFET] == 25)
		rect.left = 240;
	if (pnj[TERRORIST].hp[CAFET] <= 0)
		rect.left = 320;
	sfSprite_setTextureRect(pnj[TERRORIST].hp_spr, rect);
}