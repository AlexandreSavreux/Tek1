/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void change_hitbox_rocket(float rotation, sfIntRect *rect)
{
	if (rotation == 270.0) {
		rect->width = 21;
		rect->height = -80;
	}
	if (rotation == 90.0) {
		rect->width = -21;
		rect->height = 80;
	}
	if (rotation == 180.0) {
		rect->width = -80;
		rect->height = -21;
	}
}

int manage_hitbox_rocket(elem *elem)
{
	int i = 0;
	sfVector2f pos = sfSprite_getPosition(
		elem->inv.user.item[ROCKET].weapon[WEAPON].spr);
	sfIntRect rect = {pos.x, pos.y, 80, 21};
	float rotation = sfSprite_getRotation(
		elem->inv.user.item[ROCKET].weapon[WEAPON].spr);

	change_hitbox_rocket(rotation, &rect);
	while (i < elem->map[elem->room].nb_blocks) {
		if (sfIntRect_intersects(&rect, &elem->map[elem->room].block[i],
			NULL) == sfTrue)
			return (0);
		i++;
	}
	if (!check_pnj_hitbox(elem))
		return (0);
	if (pos.x < 0 || pos.x > 1920)
		return (0);
	if (pos.y < 0 || pos.y > 1080)
		return (0);
	return (1);
}

void manage_rocket_move_ext(user *user)
{
	sfVector2f pos;

	if (sfSprite_getRotation(user->item[ROCKET].weapon[WEAPON].spr) ==
		180.0) {
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.x -= 6;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
	if (sfSprite_getRotation(user->item[ROCKET].weapon[WEAPON].spr) ==
		270.0) {
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.y -= 6;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
}

void manage_rocket_move_extend(user *user, sfIntRect *rect)
{
	sfVector2f pos;

	if (sfSprite_getRotation(user->item[ROCKET].weapon[WEAPON].spr) ==
		0.0) {
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.x += 6;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
	if (sfSprite_getRotation(user->item[ROCKET].weapon[WEAPON].spr) ==
		90.0) {
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.y += 6;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
	manage_rocket_move_ext(user);
	(*rect) = sfSprite_getTextureRect(
		user->item[ROCKET].weapon[WEAPON].spr);
}

void manage_rocket_move(elem *elem)
{
	sfVector2f pos;
	sfIntRect rect;

	manage_rocket_move_extend(&elem->inv.user, &rect);
	(rect.left == 160) ? (rect.left = 0) : (rect.left += 80);
	if (manage_hitbox_rocket(elem) == 0) {
		rect.left = 0;
		elem->inv.user.item[ROCKET].weapon[BULLET].active = sfTrue;
		pos = sfSprite_getPosition(
			elem->inv.user.item[ROCKET].weapon[WEAPON].spr);
		pos.x -= 75;
		pos.y -= 75;
		sfSprite_setPosition(
			elem->inv.user.item[ROCKET].weapon[BULLET].spr, pos);
		elem->inv.user.item[ROCKET].weapon[WEAPON].active = sfFalse;
	}
	sfSprite_setTextureRect(elem->inv.user.item[ROCKET].weapon[WEAPON].spr,
		rect);
}
