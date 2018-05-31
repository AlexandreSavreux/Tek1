/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void manage_hall_taliban_pnj(map room, elem *elem, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(elem->pnj[TALIBAN].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_hall = {560, 600};

	if (room == HALL) {
		if (elem->pnj[TALIBAN].active[HALL] == sfFalse) {
			elem->pnj[TALIBAN].active[HALL] = sfTrue;
			sfSprite_setPosition(elem->pnj[TALIBAN].spr, pos_hall);
			sfClock_restart(elem->pnj[TALIBAN].clock);
		}
		if (elem->pnj[TALIBAN].hp[HALL] > 0 && rect_act.top > 0 &&
			elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(elem->pnj[TALIBAN].spr, rect);
		do_taliban_hall_move(elem, chicken);
		manage_taliban_hp_rect_hall(elem->pnj);
		manage_taliban_spawn(elem->pnj, room);
	}
}

void manage_cafet_taliban_pnj(map room, elem *elem, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(elem->pnj[TALIBAN].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_cafet = {1120, 600};

	if (room == CAFET) {
		if (elem->pnj[TALIBAN].active[CAFET] == sfFalse) {
			elem->pnj[TALIBAN].active[CAFET] = sfTrue;
			sfSprite_setPosition(elem->pnj[TALIBAN].spr, pos_cafet);
			sfClock_restart(elem->pnj[TALIBAN].clock);
		}
		if (elem->pnj[TALIBAN].hp[CAFET] > 0 && rect_act.top > 0 &&
			elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(elem->pnj[TALIBAN].spr, rect);
		do_taliban_cafet_move(elem, chicken);
		manage_taliban_hp_rect_cafet(elem->pnj);
		manage_taliban_spawn(elem->pnj, room);
	}
}

void manage_warehouse_taliban_pnj(map room, elem *elem, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(elem->pnj[TALIBAN].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_warehouse = {640, 360};

	if (room == WAREHOUSE) {
		if (elem->pnj[TALIBAN].active[WAREHOUSE] == sfFalse) {
			elem->pnj[TALIBAN].active[WAREHOUSE] = sfTrue;
			sfSprite_setPosition(elem->pnj[TALIBAN].spr,
				pos_warehouse);
			sfClock_restart(elem->pnj[TALIBAN].clock);
		}
		if (elem->pnj[TALIBAN].hp[WAREHOUSE] > 0 && rect_act.top > 0 &&
			elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(elem->pnj[TALIBAN].spr, rect);
		do_taliban_warehouse_move(elem, chicken);
		manage_taliban_hp_rect_warehouse(elem->pnj);
		manage_taliban_spawn(elem->pnj, room);
	}
}

void manage_kitchen_taliban_pnj(map room, elem *elem, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(elem->pnj[TALIBAN].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_kitchen = {560, 440};

	if (room == KITCHEN) {
		if (elem->pnj[TALIBAN].active[KITCHEN] == sfFalse) {
			elem->pnj[TALIBAN].active[KITCHEN] = sfTrue;
			sfSprite_setPosition(elem->pnj[TALIBAN].spr,
				pos_kitchen);
			sfClock_restart(elem->pnj[TALIBAN].clock);
		}
		if (elem->pnj[TALIBAN].hp[KITCHEN] > 0 && rect_act.top > 0 &&
			elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(elem->pnj[TALIBAN].spr, rect);
		do_taliban_kitchen_move(elem, chicken);
		manage_taliban_hp_rect(elem->pnj);
		manage_taliban_spawn(elem->pnj, room);
	}
}

void manage_taliban_pnj(map room, elem *elem, sfSprite *chicken)
{
	manage_kitchen_taliban_pnj(room, elem, chicken);
	manage_warehouse_taliban_pnj(room, elem, chicken);
	manage_cafet_taliban_pnj(room, elem, chicken);
	manage_hall_taliban_pnj(room, elem, chicken);
	if (room == SPAWN) {
		manage_taliban_spawn(elem->pnj, room);
		elem->pnj[TALIBAN].active[SPAWN] = sfFalse;
	}
}