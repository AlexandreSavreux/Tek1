/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

int create_taliban_pnj_ext(pnjs *pnj)
{
	sfVector2f pos = {1000, 600};

	pnj[TALIBAN].weapon[WEAPON].active = sfFalse;
	pnj[TALIBAN].weapon[BULLET].active = sfFalse;
	pnj[TALIBAN].weapon[BULLET].clock = sfClock_create();
	pnj[TALIBAN].weapon[WEAPON].clock = sfClock_create();
	pnj[TALIBAN].hp_tex = sfTexture_createFromFile(
		"assets/textures/pnj/hp.png", NULL);
	if (!pnj[TALIBAN].hp_tex)
		return (0);
	pnj[TALIBAN].hp_spr = sfSprite_create();
	sfSprite_setTexture(pnj[TALIBAN].hp_spr, pnj[TALIBAN].hp_tex, sfTrue);
	sfSprite_setPosition(pnj[TALIBAN].spr, pos);

	return (1);
}

int create_taliban_pnj_extend(pnjs *pnj)
{
	sfIntRect rect = {0, 0, 80, 21};
	sfIntRect rect_f = {0, 0, 150, 150};

	pnj[TALIBAN].weapon[WEAPON].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/rocket.png", NULL);
	if (!pnj[TALIBAN].weapon[WEAPON].tex)
		return (0);
	pnj[TALIBAN].weapon[WEAPON].spr = sfSprite_create();
	sfSprite_setTexture(pnj[TALIBAN].weapon[WEAPON].spr,
		pnj[TALIBAN].weapon[WEAPON].tex, sfTrue);
	sfSprite_setTextureRect(pnj[TALIBAN].weapon[WEAPON].spr, rect);
	pnj[TALIBAN].weapon[BULLET].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/fire.png", NULL);
	if (!pnj[TALIBAN].weapon[BULLET].tex)
		return (0);
	pnj[TALIBAN].weapon[BULLET].spr = sfSprite_create();
	sfSprite_setTexture(pnj[TALIBAN].weapon[BULLET].spr,
		pnj[TALIBAN].weapon[BULLET].tex, sfTrue);
	sfSprite_setTextureRect(pnj[TALIBAN].weapon[BULLET].spr, rect_f);
	return (1);
}

int create_taliban_pnj(pnjs *pnj)
{
	sfIntRect rect = {0, 0, 66, 123};
	sfIntRect rect_hp = {0, 0, 80, 20};

	pnj[TALIBAN].tex = sfTexture_createFromFile(
		"assets/textures/pnj/taliban.png", NULL);
	if (!pnj[TALIBAN].tex)
		return (0);
	pnj[TALIBAN].spr = sfSprite_create();
	sfSprite_setTexture(pnj[TALIBAN].spr, pnj[TALIBAN].tex, sfTrue);
	sfSprite_setTextureRect(pnj[TALIBAN].spr, rect);
	pnj[TALIBAN].clock = sfClock_create();
	for (unsigned int i = 0; i < NB_ROOMS; i++) {
		pnj[TALIBAN].hp[i] = 100;
		pnj[TALIBAN].active[i] = sfFalse;
	}
	if (!create_taliban_pnj_ext(pnj))
		return (0);
	if (!create_taliban_pnj_extend(pnj))
		return (0);
	sfSprite_setTextureRect(pnj[TALIBAN].hp_spr, rect_hp);
	return (1);
}

void display_taliban_pnj(sfRenderWindow *window, pnjs *pnj)
{
	if (pnj[TALIBAN].active[KITCHEN] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].hp_spr, NULL);
	}
	if (pnj[TALIBAN].active[WAREHOUSE] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].hp_spr, NULL);
	}
	if (pnj[TALIBAN].active[CAFET] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].hp_spr, NULL);
	}
	if (pnj[TALIBAN].active[HALL] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TALIBAN].hp_spr, NULL);
	}
}
