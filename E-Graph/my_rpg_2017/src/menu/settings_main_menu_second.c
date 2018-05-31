/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

void change_button(first_menu_t *main_menu, sfRenderWindow *window)
{
	sfVector2i position = sfMouse_getPositionRenderWindow(window);
	sfIntRect play = {0, 0, 300, 60};
	sfIntRect color = {300, 0, 300, 60};

	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 700 && position.y <= 760)
			sfSprite_setTextureRect(main_menu->sprite[8], color);
		else
			sfSprite_setTextureRect(main_menu->sprite[8], play);
	} else {
		sfSprite_setTextureRect(main_menu->sprite[8], play);
	}
}
