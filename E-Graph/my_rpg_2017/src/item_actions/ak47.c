/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void manage_ak47(user *user)
{
	sfIntRect rect = sfSprite_getTextureRect(
		user->item[AK47].weapon[WEAPON].spr);

	if (sfClock_getElapsedTime(
		user->item[AK47].weapon[WEAPON].clock).microseconds > 100000 &&
		user->item[AK47].weapon[WEAPON].active == sfTrue) {
		if (rect.left < 92)
			rect.left += 46;
		else
			rect.left = 0;
		sfSprite_setTextureRect(user->item[AK47].weapon[WEAPON].spr,
			rect);
		user->item[AK47].weapon[WEAPON].active = sfFalse;
	}
}

int create_ak47(user *user)
{
	sfIntRect rect = {0, 0, 46, 55};

	user->item[AK47].weapon[WEAPON].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/fire_ak.png", NULL);
	if (!user->item[AK47].weapon[WEAPON].tex)
		return (0);
	user->item[AK47].weapon[WEAPON].spr = sfSprite_create();
	sfSprite_setTexture(user->item[AK47].weapon[WEAPON].spr,
		user->item[AK47].weapon[WEAPON].tex, sfTrue);
	sfSprite_setTextureRect(user->item[AK47].weapon[WEAPON].spr, rect);
	user->item[AK47].weapon[WEAPON].active = sfFalse;
	user->item[AK47].weapon[WEAPON].clock = sfClock_create();
	return (1);
}

void ak47_extend(sfSprite *chicken, user *user, sfVector2f pos)
{
	if (sfSprite_getTextureRect(chicken).top == 72) {
		sfSprite_setRotation(user->item[AK47].weapon[WEAPON].spr,
			270.0);
		pos = sfSprite_getPosition(user->item[AK47].weapon[WEAPON].spr);
		pos.x -= 73;
		pos.y += 30;
		sfSprite_setPosition(user->item[AK47].weapon[WEAPON].spr, pos);
	}
}

void ak47_ext(sfSprite *chicken, user *user, sfVector2f pos)
{
	if (sfSprite_getTextureRect(chicken).top == 144) {
		sfSprite_setRotation(user->item[AK47].weapon[WEAPON].spr, 90.0);
		pos = sfSprite_getPosition(user->item[AK47].weapon[WEAPON].spr);
		pos.x += 96;
		pos.y -= 15;
		sfSprite_setPosition(user->item[AK47].weapon[WEAPON].spr, pos);
	}
	if (sfSprite_getTextureRect(chicken).top == 216) {
		sfSprite_setRotation(user->item[AK47].weapon[WEAPON].spr, 0.0);
		pos = sfSprite_getPosition(user->item[AK47].weapon[WEAPON].spr);
		pos.x -= 10;
		pos.y -= 70;
		sfSprite_setPosition(user->item[AK47].weapon[WEAPON].spr, pos);
	}
}

void ak47(sfSprite *chicken, user *user)
{
	sfVector2f pos = sfSprite_getPosition(chicken);

	user->item[AK47].weapon[WEAPON].active = sfTrue;
	pos.x += 24;
	pos.y += 30;
	sfSprite_setPosition(user->item[AK47].weapon[WEAPON].spr, pos);
	if (sfSprite_getTextureRect(chicken).top == 0) {
		sfSprite_setRotation(user->item[AK47].weapon[WEAPON].spr,
			180.0);
		pos = sfSprite_getPosition(user->item[AK47].weapon[WEAPON].spr);
		pos.x += 36;
		pos.y += 87;
		sfSprite_setPosition(user->item[AK47].weapon[WEAPON].spr, pos);
	}
	ak47_ext(chicken, user, pos);
	ak47_extend(chicken, user, pos);
	sfClock_restart(user->item[AK47].weapon[WEAPON].clock);
}
