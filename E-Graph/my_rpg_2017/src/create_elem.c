/*
** EPITECH PROJECT, 2018
** create_elem
** File description:
** creates elements
*/

#include "my.h"

int create_chicken_and_window(elem *elem)
{
	sfVideoMode mode = {1920, 1080, 32};

	elem->window = sfRenderWindow_create(mode, "FCK RPG",
		sfResize | sfClose, NULL);
	if (!elem->window)
		return (0);
	sfRenderWindow_setFramerateLimit(elem->window, 120);
	elem->chicken_tex = sfTexture_createFromFile(
		"assets/textures/chicken.png", NULL);
	if (!elem->chicken_tex)
		return (0);
	elem->chicken = sfSprite_create();
	sfSprite_setTexture(elem->chicken, elem->chicken_tex, sfTrue);
	elem->chicken_clock = sfClock_create();
	elem->pnj[TALIBAN].damage.clock_rocket = sfClock_create();
	elem->pnj[TALIBAN].damage.clock_ak = sfClock_create();
	elem->pnj[TALIBAN].damage.clock_cut = sfClock_create();
	elem->pnj[TERRORIST].damage.clock_rocket = sfClock_create();
	elem->pnj[TERRORIST].damage.clock_ak = sfClock_create();
	elem->pnj[TERRORIST].damage.clock_cut = sfClock_create();
	return (1);
}

int create_menu(elem *elem)
{
	sfVector2f menu_position = {1200, 220};

	elem->menu.texture[0] = sfTexture_createFromFile(
		"assets/textures/menu/ingame_menu/menu.png", NULL);
	if (!elem->menu.texture[0])
		return (0);
	elem->menu.sprite[0] = sfSprite_create();
	sfSprite_setTexture(elem->menu.sprite[0], elem->menu.texture[0],
		sfTrue);
	elem->menu.texture[1] = sfTexture_createFromFile(
		"assets/textures/menu/ingame_menu/cursor.png", NULL);
	if (!elem->menu.texture[1])
		return (0);
	elem->menu.sprite[1] = sfSprite_create();
	sfSprite_setTexture(elem->menu.sprite[1], elem->menu.texture[1],
		sfTrue);
	sfSprite_setPosition(elem->menu.sprite[0], menu_position);
	return (1);
}

int create_pnj_chicken(pnj_chicken *pnj_chicken)
{
	sfVector2f chicken_position = {1300, 360};
	sfVector2f text_position = {360, 593};

	pnj_chicken->texture[0] = sfTexture_createFromFile(
		"assets/textures/pnj/pnj_chicken.png", NULL);
	if (!pnj_chicken->texture[0])
		return (0);
	pnj_chicken->sprite[0] = sfSprite_create();
	sfSprite_setTexture(pnj_chicken->sprite[0], pnj_chicken->texture[0],
		sfTrue);
	sfSprite_setPosition(pnj_chicken->sprite[0], chicken_position);
	pnj_chicken->texture[1] = sfTexture_createFromFile(
		"assets/textures/pnj/texte_pnj.png", NULL);
	if (!pnj_chicken->texture[1])
		return (0);
	pnj_chicken->sprite[1] = sfSprite_create();
	sfSprite_setTexture(pnj_chicken->sprite[1], pnj_chicken->texture[1],
		sfTrue);
	sfSprite_setPosition(pnj_chicken->sprite[1], text_position);
	return (1);
}

int create_elem(elem *elem)
{
	if (!create_chicken_and_window(elem) ||
	!create_maps(elem) ||
	!create_inventory_window(&elem->inv) ||
	!create_menu(elem))
		return (0);
	if (!create_user_iud(&elem->inv.user) ||
	!create_pnj(elem->pnj) ||
	!create_taliban_pnj(elem->pnj) ||
	!create_stats(&elem->stats))
		return (0);
	if (!create_pnj_chicken(&elem->pnj_chicken) ||
	!create_quests(&elem->quest) ||
	!create_items(&elem->items))
		return (0);
	elem->damage.clock_ak = sfClock_create();
	elem->damage.clock_rocket = sfClock_create();
	return (1);
}
