/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

int create_pnj_extend(pnjs *pnj)
{
	sfIntRect rect_ak = {0, 0, 46, 55};
	sfVector2f pos = {1000, 600};

	pnj[TERRORIST].hp_tex = sfTexture_createFromFile(
		"assets/textures/pnj/hp.png", NULL);
	if (!pnj[TERRORIST].hp_tex)
		return (0);
	pnj[TERRORIST].hp_spr = sfSprite_create();
	sfSprite_setTexture(pnj[TERRORIST].hp_spr, pnj[TERRORIST].hp_tex,
		sfTrue);
	sfSprite_setPosition(pnj[TERRORIST].spr, pos);
	pnj[TERRORIST].weapon[WEAPON].tex = sfTexture_createFromFile(
		"assets/textures/items/ammo/fire_ak.png", NULL);
	if (!pnj[TERRORIST].weapon[WEAPON].tex)
		return (0);
	pnj[TERRORIST].weapon[WEAPON].spr = sfSprite_create();
	sfSprite_setTexture(pnj[TERRORIST].weapon[WEAPON].spr,
		pnj[TERRORIST].weapon[WEAPON].tex, sfTrue);
	sfSprite_setTextureRect(pnj[TERRORIST].weapon[WEAPON].spr, rect_ak);
	return (1);
}

int create_pnj(pnjs *pnj)
{
	sfIntRect rect = {0, 0, 66, 123};
	sfIntRect rect_hp = {0, 0, 80, 20};

	pnj[TERRORIST].tex = sfTexture_createFromFile(
		"assets/textures/pnj/terrorist.png", NULL);
	if (!pnj[TERRORIST].tex)
		return (0);
	pnj[TERRORIST].spr = sfSprite_create();
	sfSprite_setTexture(pnj[TERRORIST].spr, pnj[TERRORIST].tex, sfTrue);
	sfSprite_setTextureRect(pnj[TERRORIST].spr, rect);
	pnj[TERRORIST].clock = sfClock_create();
	for (unsigned int i = 0; i < NB_ROOMS; i++) {
		pnj[TERRORIST].hp[i] = 100;
		pnj[TERRORIST].active[i] = sfFalse;
	}
	if (!create_pnj_extend(pnj))
		return (0);
	sfSprite_setTextureRect(pnj[TERRORIST].hp_spr, rect_hp);
	pnj[TERRORIST].weapon[WEAPON].active = sfFalse;
	pnj[TERRORIST].weapon[WEAPON].clock = sfClock_create();
	return (1);
}

void display_pnj(sfRenderWindow *window, pnjs *pnj)
{
	if (pnj[TERRORIST].active[KITCHEN] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].hp_spr, NULL);
	}
	if (pnj[TERRORIST].active[WAREHOUSE] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].hp_spr, NULL);
	}
	if (pnj[TERRORIST].active[CAFET] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].hp_spr, NULL);
	}
	if (pnj[TERRORIST].active[HALL] == sfTrue) {
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].spr, NULL);
		sfRenderWindow_drawSprite(window, pnj[TERRORIST].hp_spr, NULL);
	}
}