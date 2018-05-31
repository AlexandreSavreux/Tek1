/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void change_play(sfVector2i position, menu_t *menu)
{
	if (position.x >= 828 && position.x <= 1188) {
		if (position.y >= 470 && position.y <= 530) {
			menu->texture[1] = sfTexture_createFromFile(
				"Assets/Sprites/Clic/Play.png", NULL);
			sfSprite_setTexture(menu->sprite[1], menu->texture[1],
				sfTrue);
		} else {
			menu->texture[1] = sfTexture_createFromFile(
				"Assets/Sprites/Play.png", NULL);
			sfSprite_setTexture(menu->sprite[1], menu->texture[1],
				sfTrue);
		}
	} else {
		menu->texture[1] = sfTexture_createFromFile(
			"Assets/Sprites/Play.png", NULL);
		sfSprite_setTexture(menu->sprite[1], menu->texture[1], sfTrue);
	}
}

void change_settings(sfVector2i position, menu_t *menu)
{
	if (position.x >= 828 && position.x <= 1188) {
		if (position.y >= 570 && position.y <= 630) {
			menu->texture[2] = sfTexture_createFromFile(
				"Assets/Sprites/Clic/Settings.png", NULL);
			sfSprite_setTexture(menu->sprite[2], menu->texture[2],
				sfTrue);
		} else {
			menu->texture[2] = sfTexture_createFromFile(
				"Assets/Sprites/Settings.png", NULL);
			sfSprite_setTexture(menu->sprite[2], menu->texture[2],
				sfTrue);
		}
	} else {
		menu->texture[2] = sfTexture_createFromFile(
			"Assets/Sprites/Settings.png", NULL);
		sfSprite_setTexture(menu->sprite[2], menu->texture[2], sfTrue);
	}
	change_play(position, menu);
}

void change_button(menu_t *menu)
{
	sfVector2i position = sfMouse_getPosition(NULL);

	if (position.x >= 828 && position.x <= 1188) {
		if (position.y >= 670 && position.y <= 730) {
			menu->texture[3] = sfTexture_createFromFile(
				"Assets/Sprites/Clic/Quit.png", NULL);
			sfSprite_setTexture(menu->sprite[3], menu->texture[3],
				sfTrue);
		} else {
			menu->texture[3] = sfTexture_createFromFile(
				"Assets/Sprites/Quit.png", NULL);
			sfSprite_setTexture(menu->sprite[3], menu->texture[3],
				sfTrue);
		}
	} else {
		menu->texture[3] = sfTexture_createFromFile(
			"Assets/Sprites/Quit.png", NULL);
		sfSprite_setTexture(menu->sprite[3], menu->texture[3], sfTrue);
	}
	change_settings(position, menu);
}