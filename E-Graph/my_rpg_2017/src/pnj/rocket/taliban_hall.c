/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

static int check_taliban_attack_pnj(pnjs *pnj, sfSprite *chicken)
{
	sfVector2f pos_c = sfSprite_getPosition(chicken);
	sfVector2f pos = sfSprite_getPosition(pnj[TALIBAN].spr);
	sfVector2f scale = sfSprite_getScale(pnj[TALIBAN].spr);
	int check = 0;

	if ((pos.y >= pos_c.y && pos.y + 123 <= pos_c.y) ||
		(pos.y + 51 <= pos_c.y + 72 && pos.y + 51 >= pos_c.y - 4))
		check = 1;
	if (pos_c.x > pos.x && scale.x == 1.0 && check == 1 &&
		pnj[TALIBAN].hp[HALL] > 0)
		return (1);
	if (pos_c.x < pos.x && scale.x == -1.0 && check == 1 &&
		pnj[TALIBAN].hp[HALL] > 0)
		return (1);
	return (0);
}

static void manage_taliban_animation_pnj(pnjs *pnj)
{
	sfIntRect rect = sfSprite_getTextureRect(pnj[TALIBAN].spr);

	if (sfClock_getElapsedTime(pnj[TALIBAN].clock).microseconds > 80000 &&
		pnj[TALIBAN].hp[HALL] > 0) {
		rect.top = 0;
		if (rect.left < 462)
			rect.left += 66;
		else
			rect.left = 0;
		sfClock_restart(pnj[TALIBAN].clock);
	}
	if (pnj[TALIBAN].hp[HALL] <= 0 &&
		sfClock_getElapsedTime(pnj[TALIBAN].clock).microseconds >
			80000) {
		if (rect.left < 912)
			rect.left += 114;
		sfClock_restart(pnj[TALIBAN].clock);
	}
	sfSprite_setTextureRect(pnj[TALIBAN].spr, rect);
}

static void do_taliban_hall_move_ext(pnjs *pnj, sfVector2f *pos,
	sfVector2f scale
)
{
	if (scale.x == -1.0 && pos->x >= 560 && pnj[TALIBAN].hp[HALL] > 0 &&
		pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
		pos->x -= 1;
	else if (scale.x == -1.0 && pos->x <= 560 &&
		pnj[TALIBAN].hp[HALL] > 0 &&
		pnj[TALIBAN].weapon[WEAPON].active == sfFalse) {
		pos->x -= 66;
		sfSprite_scale(pnj[TALIBAN].spr, scale);
		pos->x += 1;
	}
}

static void do_taliban_hall_move_extend(elem *elem, sfVector2f *pos,
	sfVector2f scale
)
{
	if (elem->pnj[TALIBAN].hp[HALL] <= 0 ||
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse) {
		manage_taliban_animation_pnj(elem->pnj);
	}
	if (scale.x == 1.0 && pos->x <= 1360 &&
		elem->pnj[TALIBAN].hp[HALL] > 0 &&
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse)
		pos->x += 1;
	else if (scale.x == 1.0 && pos->x >= 1360 &&
		elem->pnj[TALIBAN].hp[HALL] > 0 &&
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfFalse) {
		scale.x = -1.0;
		pos->x += 66;
		sfSprite_scale(elem->pnj[TALIBAN].spr, scale);
		pos->x -= 1;
	}
	do_taliban_hall_move_ext(elem->pnj, pos, scale);
}

void do_taliban_hall_move(elem *elem, sfSprite *chicken)
{
	sfVector2f scale = sfSprite_getScale(elem->pnj[TALIBAN].spr);
	sfVector2f pos = sfSprite_getPosition(elem->pnj[TALIBAN].spr);
	sfVector2f hp_pos = pos;
	sfIntRect rect = {0, 245, 114, 123};
	sfIntRect rect_t = sfSprite_getTextureRect(elem->pnj[TALIBAN].spr);

	if (elem->pnj[TALIBAN].hp[HALL] <= 0 && rect_t.top < 245)
		sfSprite_setTextureRect(elem->pnj[TALIBAN].spr, rect);
	else if (check_taliban_attack_pnj(elem->pnj, chicken) == 1 ||
		elem->pnj[TALIBAN].weapon[WEAPON].active == sfTrue) {
		manage_taliban_attack_pnj(elem->pnj);
		rocket_pnj(elem->pnj[TALIBAN].spr, elem);
	}
	do_taliban_hall_move_extend(elem, &pos, scale);
	if (scale.x == -1)
		hp_pos.x -= 80;
	if (elem->pnj[TALIBAN].weapon[BULLET].active == sfTrue)
		do_taliban_explosion(elem->pnj);
	sfSprite_setPosition(elem->pnj[TALIBAN].spr, pos);
	sfSprite_setPosition(elem->pnj[TALIBAN].hp_spr, hp_pos);
}