/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include <stdio.h>
#include "my.h"

int create_user_iud_extend(user *user)
{
	sfVector2f pos = {910, 900};
	char *textures[] = {"assets/textures/items/knife.png",
	"assets/textures/items/rocket.png", "assets/textures/items/ak47.png",
	"assets/textures/items/grenade.png"};

	for (int i = 0; i < NB_ITEMS; i++) {
		user->item[i].tex = sfTexture_createFromFile(textures[i], NULL);
		if (!user->item[i].tex)
			return (0);
		user->item[i].spr = sfSprite_create();
		sfSprite_setTexture(user->item[i].spr, user->item[i].tex,
			sfTrue);
		sfSprite_setPosition(user->item[i].spr, pos);
	}
	user->item[ROCKET].weapon[WEAPON].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/rocket.png", NULL);
	if (!user->item[ROCKET].weapon[WEAPON].tex || !create_ak47(user))
		return (0);
	return (1);
}

int create_user_iud_ext(user *user)
{
	sfIntRect rect = {0, 0, 150, 150};

	user->item[ROCKET].weapon[WEAPON].spr = sfSprite_create();
	sfSprite_setTexture(user->item[ROCKET].weapon[WEAPON].spr,
		user->item[ROCKET].weapon[WEAPON].tex, sfTrue);
	user->item[KNIFE].weapon[WEAPON].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/cut.png", NULL);
	user->item[ROCKET].weapon[BULLET].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/fire.png", NULL);
	if (!user->item[KNIFE].weapon[WEAPON].tex ||
	!user->item[ROCKET].weapon[BULLET].tex)
		return (0);
	user->item[KNIFE].weapon[WEAPON].spr = sfSprite_create();
	sfSprite_setTexture(user->item[KNIFE].weapon[WEAPON].spr,
		user->item[KNIFE].weapon[WEAPON].tex, sfTrue);
	user->item[ROCKET].weapon[BULLET].spr = sfSprite_create();
	sfSprite_setTexture(user->item[ROCKET].weapon[BULLET].spr,
		user->item[ROCKET].weapon[BULLET].tex, sfTrue);
	sfSprite_setTextureRect(user->item[ROCKET].weapon[BULLET].spr, rect);
	return (1);
}

int create_user_iud(user *user)
{
	sfVector2f pos = {910, 900};

	user->tex = sfTexture_createFromFile
		("assets/textures/inventory/user.png", NULL);
	if (!user->tex)
		return (0);
	user->spr = sfSprite_create();
	sfSprite_setTexture(user->spr, user->tex, sfTrue);
	sfSprite_setPosition(user->spr, pos);
	if (!create_user_iud_extend(user))
		return (0);
	if (!create_user_iud_ext(user))
		return (0);
	user->item[ROCKET].weapon[WEAPON].active = sfFalse;
	user->item[KNIFE].weapon[WEAPON].active = sfFalse;
	user->item[KNIFE].weapon[WEAPON].clock = sfClock_create();
	user->item[ROCKET].weapon[BULLET].active = sfFalse;
	user->item[ROCKET].weapon[BULLET].clock = sfClock_create();
	user->used = -1;
	return (1);
}

void display_user_iud(user user, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, user.spr, NULL);
	if (user.used > -1) {
		sfRenderWindow_drawSprite(window, user.item[user.used].spr,
			NULL);
	}
}

void manage_user_item(sfVector2f pos, inventory *inv)
{
	sfVector2f pos_i = {920, 906};
	int i = 0;

	while (i < NB_ITEMS) {
		if (pos.x - 28 == sfSprite_getPosition(inv->item[i].spr).x &&
			pos.y + 30 ==
				sfSprite_getPosition(inv->item[i].spr).y) {
			inv->user.used = i;
			sfSprite_setPosition(inv->user.item[i].spr, pos_i);
		}
		i++;
	}
}
