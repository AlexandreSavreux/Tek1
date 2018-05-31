/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

void do_explosion(user *user)
{
	sfIntRect rect = sfSprite_getTextureRect(
		user->item[ROCKET].weapon[BULLET].spr);

	if (sfSprite_getTextureRect(
		user->item[ROCKET].weapon[BULLET].spr).left == 750) {
		user->item[ROCKET].weapon[BULLET].active = sfFalse;
		rect.left = 0;
	} else if (sfClock_getElapsedTime(
		user->item[ROCKET].weapon[BULLET].clock).microseconds > 50000) {
		rect.left += 150;
		sfClock_restart(user->item[ROCKET].weapon[BULLET].clock);
	}
	sfSprite_setTextureRect(user->item[ROCKET].weapon[BULLET].spr, rect);
}

void rocket_shoot_extend(sfSprite *chicken, user *user, sfVector2f pos)
{
	if (sfSprite_getTextureRect(chicken).top == 144) {
		sfSprite_setRotation(user->item[ROCKET].weapon[WEAPON].spr,
			0.0);
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.x += 10;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
	if (sfSprite_getTextureRect(chicken).top == 216) {
		sfSprite_setRotation(user->item[ROCKET].weapon[WEAPON].spr,
			270.0);
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.x += 4;
		pos.y += 6;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
}

void rocket_shoot_ext(sfSprite *chicken, user *user, sfVector2f pos)
{
	if (sfSprite_getTextureRect(chicken).top == 0) {
		sfSprite_setRotation(user->item[ROCKET].weapon[WEAPON].spr,
			90.0);
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.x += 24;
		pos.y += 3;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
	if (sfSprite_getTextureRect(chicken).top == 72) {
		sfSprite_setRotation(user->item[ROCKET].weapon[WEAPON].spr,
			180.0);
		pos = sfSprite_getPosition(
			user->item[ROCKET].weapon[WEAPON].spr);
		pos.x += 10;
		pos.y += 19;
		sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr,
			pos);
	}
}

void rocket_shoot(sfSprite *chicken, user *user)
{
	sfIntRect rect = {0, 0, 80, 21};
	sfVector2f pos = sfSprite_getPosition(chicken);

	user->item[ROCKET].weapon[WEAPON].active = sfTrue;
	pos.x += 24;
	pos.y += 30;
	sfSprite_setPosition(user->item[ROCKET].weapon[WEAPON].spr, pos);
	rocket_shoot_ext(chicken, user, pos);
	rocket_shoot_extend(chicken, user, pos);
	sfSprite_setTextureRect(user->item[ROCKET].weapon[WEAPON].spr, rect);
}

void display_rockets(sfRenderWindow *window, elem elem)
{
	if (elem.inv.user.item[ROCKET].weapon[WEAPON].active == sfTrue)
		sfRenderWindow_drawSprite(window,
			elem.inv.user.item[ROCKET].weapon[WEAPON].spr, NULL);
	if (elem.inv.user.item[ROCKET].weapon[BULLET].active == sfTrue)
		sfRenderWindow_drawSprite(window,
			elem.inv.user.item[ROCKET].weapon[BULLET].spr, NULL);
	if (elem.pnj[TALIBAN].weapon[WEAPON].active == sfTrue)
		sfRenderWindow_drawSprite(window,
			elem.pnj[TALIBAN].weapon[WEAPON].spr, NULL);
	if (elem.pnj[TALIBAN].weapon[BULLET].active == sfTrue)
		sfRenderWindow_drawSprite(window,
			elem.pnj[TALIBAN].weapon[BULLET].spr, NULL);
}
