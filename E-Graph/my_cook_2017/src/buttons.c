/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int settings_click(sfEvent event, menu_t *menu)
{
	sfVector2f position = {(float)event.mouseButton.x,
		(float)event.mouseButton.y};

	if (position.x >= 750 && position.x <= 1110) {
		if (position.y >= 600 && position.y <= 660) {
			sfMusic_play(menu->click);
			return (1);
		}
	}
	if (position.x >= 450 && position.x <= 520) {
		if (position.y >= 490 && position.y <= 570 && menu->n != 0) {
			sfMusic_play(menu->click);
			change_volume_minus(menu);
		}
	}
	if (position.x >= 1350 && position.x <= 1450) {
		if (position.y >= 490 && position.y <= 570 && menu->n != 8) {
			sfMusic_play(menu->click);
			change_volume_plus(menu);
		}
	}
	return (0);
}