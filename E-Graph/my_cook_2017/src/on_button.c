/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void change_volume_minus(menu_t *menu)
{
	int volume;

	menu->n--;
	menu->texture[4] = sfTexture_createFromFile(menu->string[menu->n],
		NULL);
	sfSprite_setTexture(menu->sprite[4], menu->texture[4], sfTrue);
	volume = menu->n * 7;
	sfMusic_setVolume(menu->music, volume);
}

void change_volume_plus(menu_t *menu)
{
	int volume;

	menu->n++;
	menu->texture[4] = sfTexture_createFromFile(menu->string[menu->n],
		NULL);
	sfSprite_setTexture(menu->sprite[4], menu->texture[4], sfTrue);
	volume = menu->n * 7;
	sfMusic_setVolume(menu->music, volume);
}

void change_button_settings(menu_t *menu)
{
	sfVector2i position = sfMouse_getPosition(NULL);

	if (position.x >= 828 && position.x <= 1188) {
		if (position.y >= 670 && position.y <= 730) {
			menu->texture[5] = sfTexture_createFromFile(
				"Assets/Sprites/Clic/back.png", NULL);
			sfSprite_setTexture(menu->sprite[5], menu->texture[5],
				sfTrue);
		} else {
			menu->texture[5] = sfTexture_createFromFile(
				"Assets/Sprites/back.png", NULL);
			sfSprite_setTexture(menu->sprite[5], menu->texture[5],
				sfTrue);
		}
	} else {
		menu->texture[5] = sfTexture_createFromFile(
			"Assets/Sprites/back.png", NULL);
		sfSprite_setTexture(menu->sprite[5], menu->texture[5], sfTrue);
	}
	change_button_plus(position, menu);
}

void change_button_minus(sfVector2i position, menu_t *menu)
{
	if (position.x >= 517 && position.x <= 592) {
		if (position.y >= 565 && position.y <= 623) {
			menu->texture[7] = sfTexture_createFromFile(
				"Assets/Sprites/Clic/Volume_minus.png", NULL);
			sfSprite_setTexture(menu->sprite[7], menu->texture[7],
				sfTrue);
		} else {
			menu->texture[7] = sfTexture_createFromFile(
				"Assets/Sprites/Volume_minus.png", NULL);
			sfSprite_setTexture(menu->sprite[7], menu->texture[7],
				sfTrue);
		}
	} else {
		menu->texture[7] = sfTexture_createFromFile(
			"Assets/Sprites/Volume_minus.png", NULL);
		sfSprite_setTexture(menu->sprite[7], menu->texture[7], sfTrue);
	}
}

void change_button_plus(sfVector2i position, menu_t *menu)
{
	if (position.x >= 1450 && position.x <= 1525) {
		if (position.y >= 565 && position.y <= 623) {
			menu->texture[6] = sfTexture_createFromFile(
				"Assets/Sprites/Clic/Volume_plus.png", NULL);
			sfSprite_setTexture(menu->sprite[6], menu->texture[6],
				sfTrue);
		} else {
			menu->texture[6] = sfTexture_createFromFile(
				"Assets/Sprites/Volume_plus.png", NULL);
			sfSprite_setTexture(menu->sprite[6], menu->texture[6],
				sfTrue);
		}
	} else {
		menu->texture[6] = sfTexture_createFromFile(
			"Assets/Sprites/Volume_plus.png", NULL);
		sfSprite_setTexture(menu->sprite[6], menu->texture[6], sfTrue);
	}
	change_button_minus(position, menu);
}