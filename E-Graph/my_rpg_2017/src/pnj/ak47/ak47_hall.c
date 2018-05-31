/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

static void manage_animation_pnj(pnjs *pnj)
{
	sfIntRect rect = sfSprite_getTextureRect(pnj[TERRORIST].spr);

	if (sfClock_getElapsedTime(pnj[TERRORIST].clock).microseconds > 80000 &&
		pnj[TERRORIST].hp[HALL] > 0) {
		rect.top = 0;
		if (rect.left < 462)
			rect.left += 66;
		else
			rect.left = 0;
		sfClock_restart(pnj[TERRORIST].clock);
	}
	if (pnj[TERRORIST].hp[HALL] <= 0 &&
		sfClock_getElapsedTime(pnj[TERRORIST].clock).microseconds >
			80000) {
		if (rect.left < 888)
			rect.left += 111;
		sfClock_restart(pnj[TERRORIST].clock);
	}
	sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
}

static int check_attack_pnj_hall(pnjs *pnj, sfSprite *chicken)
{
	sfVector2f pos_c = sfSprite_getPosition(chicken);
	sfVector2f pos = sfSprite_getPosition(pnj[TERRORIST].spr);
	sfVector2f scale = sfSprite_getScale(pnj[TERRORIST].spr);
	int check = 0;

	if ((pos.y >= pos_c.y && pos.y + 123 <= pos_c.y) ||
		(pos.y + 51 <= pos_c.y + 72 && pos.y + 51 >= pos_c.y - 4))
		check = 1;
	if (pos_c.x > pos.x && scale.x == 1.0 && check == 1 &&
		pnj[TERRORIST].hp[HALL] > 0)
		return (1);
	if (pos_c.x < pos.x && scale.x == -1.0 && check == 1 &&
		pnj[TERRORIST].hp[HALL] > 0)
		return (1);
	return (0);
}

static void do_hall_move_ext(pnjs *pnj, sfVector2f *pos, sfVector2f scale)
{
	if (scale.x == -1.0 && pos->x >= 720 && pnj[TERRORIST].hp[HALL] > 0 &&
		pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
		pos->x -= 1;
	else if (scale.x == -1.0 && pos->x <= 720 &&
		pnj[TERRORIST].hp[HALL] > 0 &&
		pnj[TERRORIST].weapon[WEAPON].active == sfFalse) {
		pos->x -= 66;
		sfSprite_scale(pnj[TERRORIST].spr, scale);
		pos->x += 1;
	}
}

static void do_hall_move_extend(pnjs *pnj, sfVector2f *pos, sfVector2f scale)
{
	if (scale.x == 1.0 && pos->x <= 1200 && pnj[TERRORIST].hp[HALL] > 0 &&
		pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
		pos->x += 1;
	else if (scale.x == 1.0 && pos->x >= 1200 &&
		pnj[TERRORIST].hp[HALL] > 0 &&
		pnj[TERRORIST].weapon[WEAPON].active == sfFalse) {
		scale.x = -1.0;
		pos->x += 66;
		sfSprite_scale(pnj[TERRORIST].spr, scale);
		pos->x -= 1;
	}
	do_hall_move_ext(pnj, pos, scale);
}

void do_hall_move(pnjs *pnj, sfSprite *chicken)
{
	sfVector2f scale = sfSprite_getScale(pnj[TERRORIST].spr);
	sfVector2f pos = sfSprite_getPosition(pnj[TERRORIST].spr);
	sfVector2f hp_pos = pos;
	sfIntRect rect = {0, 246, 111, 123};
	sfIntRect rect_t = sfSprite_getTextureRect(pnj[TERRORIST].spr);

	if (pnj[TERRORIST].hp[HALL] <= 0 && rect_t.top < 246)
		sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
	else if (check_attack_pnj_hall(pnj, chicken) == 1) {
		manage_attack_pnj_hall(pnj);
		ak47_pnj_hall(pnj[TERRORIST].spr, pnj);
	} else
		pnj[TERRORIST].weapon[WEAPON].active = sfFalse;
	do_hall_move_extend(pnj, &pos, scale);
	if (pnj[TERRORIST].hp[HALL] <= 0 ||
		pnj[TERRORIST].weapon[WEAPON].active == sfFalse)
		manage_animation_pnj(pnj);
	if (scale.x == -1)
		hp_pos.x -= 80;
	sfSprite_setPosition(pnj[TERRORIST].spr, pos);
	sfSprite_setPosition(pnj[TERRORIST].hp_spr, hp_pos);
}