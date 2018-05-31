/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

void color_button_play_select(first_menu_t *main_menu, elem elem)
{
	sfVector2i position = sfMouse_getPositionRenderWindow(elem.window);
	sfIntRect play = {0, 0, 300, 60};
	sfIntRect color = {300, 0, 300, 60};

	if (position.x >= 810 && position.x <= 1110 && position.y >= 700 &&
		position.y <= 760)
		sfSprite_setTextureRect(main_menu->sprite[7], color);
	else
		sfSprite_setTextureRect(main_menu->sprite[7], play);
	if (position.x >= 810 && position.x <= 1110 && position.y >= 780 &&
		position.y <= 840)
		sfSprite_setTextureRect(main_menu->sprite[14], color);
	else
		sfSprite_setTextureRect(main_menu->sprite[14], play);
}

void prepare_screen(clock_d *hour, first_menu_t *main_menu)
{
	sfIntRect rect = {0, 0, 300, 60};

	hour->clock = sfClock_create();
	hour->time = sfClock_getElapsedTime(hour->clock);
	hour->second = hour->time.microseconds / 1000000.0;
	sfSprite_setTextureRect(main_menu->sprite[7], rect);
	sfSprite_setTextureRect(main_menu->sprite[14], rect);
}

void display_my_chicken(first_menu_t *main_menu, sfRenderWindow *window)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, main_menu->sprite[0], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[4], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[5], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[6], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[7], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[14], NULL);
	sfRenderWindow_display(window);
}
