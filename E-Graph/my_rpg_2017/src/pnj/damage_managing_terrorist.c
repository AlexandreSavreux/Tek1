/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void damage_ak47_terrorist(elem *elem, sfVector2f pos, sfVector2f pos_a)
{
	sfIntRect rect = sfSprite_getTextureRect(elem->chicken);

	if ((rect.top == 144 && pos.x > pos_a.x) ||
		(rect.top == 72 && pos.x < pos_a.x)) {
		if (check_time_ak47(&elem->pnj[TERRORIST].damage) == 0 &&
			elem->inv.user.item[AK47].weapon[WEAPON].active ==
				sfTrue)
			elem->pnj[TERRORIST].hp[elem->room] -=
				elem->stats.power;
	}
}

void damage_rocket_terrorist(elem *elem, sfVector2f pos, sfVector2f pos_e)
{
	if ((pos.y >= pos_e.y && pos.y <= pos_e.y + 150) ||
		(pos.y + 123 >= pos_e.y && pos.y + 123 <= pos_e.y + 150)) {
		if (check_time_rocket(&elem->pnj[TERRORIST].damage) == 0 &&
			elem->inv.user.item[ROCKET].weapon[BULLET].active ==
				sfTrue)
			elem->pnj[TERRORIST].hp[elem->room] -= 100;
	}
}

void damage_knife_terrorist(elem *elem, sfVector2f pos, sfVector2f pos_k)
{
	if ((pos_k.y >= pos.y && pos_k.y <= pos.y + 123) ||
		(pos_k.y + 10 >= pos.y && pos_k.y + 10 <= pos_k.y + 123)) {
		if (check_time_knife(&elem->pnj[TERRORIST].damage) == 0 &&
			elem->inv.user.item[KNIFE].weapon[WEAPON].active ==
				sfTrue)
			elem->pnj[TERRORIST].hp[elem->room] -=
				elem->stats.power;
	}
}

void damage_managing_terrorist(elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(elem->pnj[TERRORIST].spr);
	sfVector2f pos_e = sfSprite_getPosition(
		elem->inv.user.item[ROCKET].weapon[BULLET].spr);
	sfVector2f pos_k = sfSprite_getPosition(
		elem->inv.user.item[KNIFE].weapon[WEAPON].spr);
	sfVector2f pos_a = sfSprite_getPosition(elem->chicken);

	if ((pos.x >= pos_e.x && pos.x <= pos_e.x + 150) ||
		(pos.x + 68 >= pos_e.x && pos.x + 68 <= pos_e.x + 150))
		damage_rocket_terrorist(elem, pos, pos_e);
	if ((pos.y >= pos_a.y - 40 && pos.y <= pos_a.y + 32) ||
		(pos.y + 40 >= pos_a.y - 40 && pos.y + 40 <= pos_a.y + 72))
		damage_ak47_terrorist(elem, pos, pos_a);
	if ((pos.x >= pos_k.x - 80 && pos.x <= pos_k.x + 80) ||
		(pos.x + 68 >= pos_k.x - 80 && pos.x + 68 <= pos_k.x + 80))
		damage_knife_terrorist(elem, pos, pos_k);
}
