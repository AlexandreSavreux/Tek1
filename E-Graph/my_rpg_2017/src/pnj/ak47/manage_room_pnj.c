/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void manage_hall_pnj(map room, pnjs *pnj, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(pnj[TERRORIST].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_hall = {640, 120};

	if (room == HALL) {
		if (pnj[TERRORIST].active[HALL] == sfFalse) {
			pnj[TERRORIST].active[HALL] = sfTrue;
			sfSprite_setPosition(pnj[TERRORIST].spr, pos_hall);
			sfClock_restart(pnj[TERRORIST].clock);
		}
		if (pnj[TERRORIST].hp[HALL] > 0 && rect_act.top > 0 &&
			pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
		do_hall_move(pnj, chicken);
		manage_hp_rect_hall(pnj);
		manage_spawn(pnj, room);
	}
}

void manage_cafet_pnj(map room, pnjs *pnj, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(pnj[TERRORIST].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_cafet = {480, 280};

	if (room == CAFET) {
		if (pnj[TERRORIST].active[CAFET] == sfFalse) {
			pnj[TERRORIST].active[CAFET] = sfTrue;
			sfSprite_setPosition(pnj[TERRORIST].spr, pos_cafet);
			sfClock_restart(pnj[TERRORIST].clock);
		}
		if (pnj[TERRORIST].hp[CAFET] > 0 && rect_act.top > 0 &&
			pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
		do_cafet_move(pnj, chicken);
		manage_hp_rect_cafet(pnj);
		manage_spawn(pnj, room);
	}
}

void manage_warehouse_pnj(map room, pnjs *pnj, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(pnj[TERRORIST].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_warehouse = {640, 680};

	if (room == WAREHOUSE) {
		if (pnj[TERRORIST].active[WAREHOUSE] == sfFalse) {
			pnj[TERRORIST].active[WAREHOUSE] = sfTrue;
			sfSprite_setPosition(pnj[TERRORIST].spr, pos_warehouse);
			sfClock_restart(pnj[TERRORIST].clock);
		}
		if (pnj[TERRORIST].hp[WAREHOUSE] > 0 && rect_act.top > 0 &&
			pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
		do_warehouse_move(pnj, chicken);
		manage_hp_rect_warehouse(pnj);
		manage_spawn(pnj, room);
	}
}

void manage_kitchen_pnj(map room, pnjs *pnj, sfSprite *chicken)
{
	sfIntRect rect_act = sfSprite_getTextureRect(pnj[TERRORIST].spr);
	sfIntRect rect = {0, 0, 66, 123};
	sfVector2f pos_kitchen = {1000, 600};

	if (room == KITCHEN) {
		if (pnj[TERRORIST].active[KITCHEN] == sfFalse) {
			pnj[TERRORIST].active[KITCHEN] = sfTrue;
			sfSprite_setPosition(pnj[TERRORIST].spr, pos_kitchen);
			sfClock_restart(pnj[TERRORIST].clock);
		}
		if (pnj[TERRORIST].hp[KITCHEN] > 0 && rect_act.top > 0 &&
			pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
			sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
		do_kitchen_move(pnj, chicken);
		manage_hp_rect(pnj);
		manage_spawn(pnj, room);
	}
}

void manage_pnj(map room, pnjs *pnj, sfSprite *chicken)
{
	manage_kitchen_pnj(room, pnj, chicken);
	manage_warehouse_pnj(room, pnj, chicken);
	manage_cafet_pnj(room, pnj, chicken);
	manage_hall_pnj(room, pnj, chicken);
	if (room == SPAWN) {
		manage_spawn(pnj, room);
		pnj[TERRORIST].active[SPAWN] = sfFalse;
	}
}