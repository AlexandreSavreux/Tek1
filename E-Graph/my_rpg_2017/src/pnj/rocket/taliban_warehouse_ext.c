/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void manage_taliban_attack_warehouse_pnj(pnjs *pnj)
{
	sfIntRect rect = sfSprite_getTextureRect(pnj[TALIBAN].spr);

	if (pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
		rect.left = 0;
	rect.top = 123;
	if (sfClock_getElapsedTime(pnj[TALIBAN].clock).microseconds > 80000 &&
		pnj[TALIBAN].hp[WAREHOUSE] > 0) {
		rect.top = 123;
		if (rect.left < 340)
			rect.left += 68;
		else
			rect.left = 0;
		sfClock_restart(pnj[TALIBAN].clock);
	}
	sfSprite_setTextureRect(pnj[TALIBAN].spr, rect);
}

void manage_taliban_hp_rect_warehouse(pnjs *pnj)
{
	sfIntRect rect = {0, 0, 80, 20};

	if (pnj[TALIBAN].hp[WAREHOUSE] == 75)
		rect.left = 80;
	if (pnj[TALIBAN].hp[WAREHOUSE] == 50)
		rect.left = 160;
	if (pnj[TALIBAN].hp[WAREHOUSE] == 25)
		rect.left = 240;
	if (pnj[TALIBAN].hp[WAREHOUSE] <= 0)
		rect.left = 320;
	sfSprite_setTextureRect(pnj[TALIBAN].hp_spr, rect);
}