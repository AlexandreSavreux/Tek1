/*
** EPITECH PROJECT, 2018
** init_value
** File description:
** initializes values
*/

#include "my.h"

void init_pnj_and_stats(elem *elem)
{
	sfIntRect rect = sfSprite_getTextureRect(elem->pnj[TERRORIST].spr);
	sfVector2f pos = {-200, -200};

	rect.top = 0;
	sfSprite_setTextureRect(elem->pnj[TERRORIST].spr, rect);
	elem->stats.active = sfFalse;
	elem->stats.life = 100;
	elem->stats.power = 25;
	elem->stats.xp = 0;
	elem->stats.level = 1;
	elem->pnj[TALIBAN].weapon[WEAPON].active = sfFalse;
	elem->pnj[TALIBAN].weapon[BULLET].active = sfFalse;
	elem->inv.user.item[KNIFE].nbr = 0;
	elem->inv.user.item[ROCKET].nbr = 0;
	elem->inv.user.item[AK47].nbr = 0;
	sfSprite_setPosition(elem->pnj[TALIBAN].weapon[BULLET].spr, pos);
}

void init_values(elem *elem)
{
	sfVector2f pos = {1359, 390};
	sfIntRect chicken_rect = {72 + 288 * elem->stats.color, 0, 72, 72};
	sfVector2f cursor_position = {1307, 365};
	sfIntRect stats_chicken_rect = {0, 184 * elem->stats.color, 184, 184};

	sfSprite_setTextureRect(elem->stats.sprite[CHICKEN],
				stats_chicken_rect);
	elem->game = sfTrue;
	elem->room = SPAWN;
	sfSprite_setPosition(elem->chicken, pos);
	sfSprite_setTextureRect(elem->chicken, chicken_rect);
	sfSprite_setPosition(elem->menu.sprite[1], cursor_position);
	elem->inv.item[KNIFE].nbr = 0;
	elem->inv.item[ROCKET].nbr = 0;
	elem->inv.item[AK47].nbr = 0;
	init_pnj_and_stats(elem);
}
