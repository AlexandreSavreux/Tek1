/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void manage_movement_cut(sfVector2f *pos, user *user)
{
	float rotation = sfSprite_getRotation(
		user->item[KNIFE].weapon[WEAPON].spr);

	if (rotation == 0.0)
		pos->x -= 3;
	if (rotation == 90.0)
		pos->y -= 3;
	if (rotation == 180.0)
		pos->x += 3;
	if (rotation == 270.0)
		pos->y += 3;
}

void manage_movement_cut_back(sfVector2f *pos, user *user)
{
	float rotation = sfSprite_getRotation(
		user->item[KNIFE].weapon[WEAPON].spr);

	if (rotation == 0.0)
		pos->x += 3;
	if (rotation == 90.0)
		pos->y += 3;
	if (rotation == 180.0)
		pos->x -= 3;
	if (rotation == 270.0)
		pos->y -= 3;
}

void manage_cut(user *user)
{
	sfVector2f pos = sfSprite_getPosition(
		user->item[KNIFE].weapon[WEAPON].spr);

	if (sfClock_getElapsedTime(
		user->item[KNIFE].weapon[WEAPON].clock).microseconds > 150000) {
		sfClock_restart(user->item[KNIFE].weapon[WEAPON].clock);
		user->item[KNIFE].weapon[WEAPON].active = sfFalse;
	} else if (sfClock_getElapsedTime(
		user->item[KNIFE].weapon[WEAPON].clock).microseconds > 75000) {
		manage_movement_cut(&pos, user);
		sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	} else {
		manage_movement_cut_back(&pos, user);
		sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	}
}