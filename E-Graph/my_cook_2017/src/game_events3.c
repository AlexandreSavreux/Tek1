/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int check_pos(sfVector2f position, menu_t *menu, int *n, int *i)
{
	if (position.x >= 750 && position.x <= 1110) {
		if (position.y >= 600 && position.y <= 660) {
			sfMusic_play(menu->click);
			(*n)++;
			(*i)++;
			menu->texture[0] = sfTexture_createFromFile(
				"Assets/Sprites/menu.jpg", NULL);
			sfSprite_setTexture(menu->sprite[0], menu->texture[0],
				sfTrue);
		}
		if (position.y >= 400 && position.y <= 460) {
			sfMusic_play(menu->click);
			(*i)++;
		}
		if (position.y >= 500 && position.y <= 560) {
			sfMusic_play(menu->click);
			return (42);
		}
	}
	return (0);
}