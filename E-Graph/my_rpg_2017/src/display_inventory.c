/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

int create_inventory_extend(inventory *inv)
{
	int i = 0;
	char *textures[] = {"assets/textures/items/knife.png",
		"assets/textures/items/rocket.png",
		"assets/textures/items/ak47.png",
		"assets/textures/items/grenade.png"};

	for (i = 0; i < NB_ITEMS; i++) {
		inv->item[i].tex = sfTexture_createFromFile(textures[i], NULL);
		inv->item[i].font = sfFont_createFromFile(
			"assets/font/font.ttf");
		if (!inv->item[i].tex || !inv->item[i].font)
			return (0);
		inv->item[i].spr = sfSprite_create();
		sfSprite_setTexture(inv->item[i].spr, inv->item[i].tex, sfTrue);
		inv->item[i].text = sfText_create();
	}
	for (i = 0; i < NB_ITEMS; i++)
		inv->item[i].nbr = 0;
	return (1);
}

int create_inventory_window(inventory *inv)
{
	sfVector2f pos_inventory = {600, 100};
	sfVector2f pos_cursor = {658, 235};

	inv->tex = sfTexture_createFromFile
		("assets/textures/inventory/inv.png", NULL);
	inv->cur_tex = sfTexture_createFromFile
		("assets/textures/inventory/cursor.png", NULL);
	if (!inv->tex || !inv->cur_tex)
		return (0);
	inv->spr = sfSprite_create();
	sfSprite_setTexture(inv->spr, inv->tex, sfTrue);
	inv->cur_spr = sfSprite_create();
	sfSprite_setTexture(inv->cur_spr, inv->cur_tex, sfTrue);
	if (!create_inventory_extend(inv))
		return (0);
	inv->active = sfFalse;
	sfSprite_setPosition(inv->spr, pos_inventory);
	sfSprite_setPosition(inv->cur_spr, pos_cursor);
	return (1);
}

void display_items(sfRenderWindow *window, inventory inv)
{
	for (int i = 0; i < NB_ITEMS; i++) {
		if (inv.item[i].nbr > 0) {
			sfRenderWindow_drawSprite(window, inv.item[i].spr,
				NULL);
			sfRenderWindow_drawText(window, inv.item[i].text, NULL);
		}
	}
}

void display_inventory(sfRenderWindow *window, inventory inv)
{
	if (inv.active == sfTrue) {
		sfRenderWindow_drawSprite(window, inv.spr, NULL);
		sfRenderWindow_drawSprite(window, inv.cur_spr, NULL);
		display_items(window, inv);
	}
}

void cursor_movements(inventory *inv, sfEvent event)
{
	sfVector2f cursor_pos = sfSprite_getPosition(inv->cur_spr);

	if (event.key.code == sfKeyUp && cursor_pos.y > 235)
			cursor_pos.y -= 121;
	if (event.key.code == sfKeyDown && cursor_pos.y < 535)
			cursor_pos.y += 121;
	if (event.key.code == sfKeyLeft && cursor_pos.x > 658)
			cursor_pos.x -= 119;
	if (event.key.code == sfKeyRight && cursor_pos.x < 1015)
			cursor_pos.x += 119;
	sfSprite_setPosition(inv->cur_spr, cursor_pos);
}
