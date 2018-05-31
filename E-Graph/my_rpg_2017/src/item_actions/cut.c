/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void cut_extend(sfSprite *chicken, user *user, sfVector2f pos)
{
	if (sfSprite_getTextureRect(chicken).top == 72) {
		sfSprite_setRotation(user->item[KNIFE].weapon[WEAPON].spr,
			180.0);
		pos = sfSprite_getPosition(
			user->item[KNIFE].weapon[WEAPON].spr);
		pos.x += 15;
		pos.y += 15;
		sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	}
}

void cut_ext(sfSprite *chicken, user *user, sfVector2f pos)
{
	if (sfSprite_getTextureRect(chicken).top == 144) {
		sfSprite_setRotation(user->item[KNIFE].weapon[WEAPON].spr, 0.0);
		pos = sfSprite_getPosition(
			user->item[KNIFE].weapon[WEAPON].spr);
		pos.x += 10;
		pos.y += 6;
		sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	}
	if (sfSprite_getTextureRect(chicken).top == 216) {
		sfSprite_setRotation(user->item[KNIFE].weapon[WEAPON].spr,
			270.0);
		pos = sfSprite_getPosition(
			user->item[KNIFE].weapon[WEAPON].spr);
		pos.x += 10;
		pos.y += 20;
		sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	}
}

void cut(sfSprite *chicken, user *user)
{
	sfVector2f pos = sfSprite_getPosition(chicken);

	user->item[KNIFE].weapon[WEAPON].active = sfTrue;
	pos.x += 24;
	pos.y += 30;
	sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	if (sfSprite_getTextureRect(chicken).top == 0) {
		sfSprite_setRotation(user->item[KNIFE].weapon[WEAPON].spr,
			90.0);
		pos = sfSprite_getPosition(
			user->item[KNIFE].weapon[WEAPON].spr);
		pos.x += 18;
		sfSprite_setPosition(user->item[KNIFE].weapon[WEAPON].spr, pos);
	}
	cut_ext(chicken, user, pos);
	cut_extend(chicken, user, pos);
	sfClock_restart(user->item[KNIFE].weapon[WEAPON].clock);
}

void display_cut(sfRenderWindow *window, user user)
{
	if (user.item[KNIFE].weapon[WEAPON].active == sfTrue)
		sfRenderWindow_drawSprite(window,
			user.item[KNIFE].weapon[WEAPON].spr, NULL);
}

void display_ak47(sfRenderWindow *window, elem elem)
{
	if (elem.inv.user.item[AK47].weapon[WEAPON].active == sfTrue) {
		sfRenderWindow_drawSprite(window,
			elem.inv.user.item[AK47].weapon[WEAPON].spr, NULL);
	}
	if (elem.pnj[TERRORIST].weapon[WEAPON].active == sfTrue) {
		sfRenderWindow_drawSprite(window,
			elem.pnj[TERRORIST].weapon[WEAPON].spr, NULL);
	}
}
