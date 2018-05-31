/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

int help_event(sfEvent event)
{
	if (event.key.code == sfKeyEscape)
		return (1);
	else
		return (0);
}

int display_help(sfRenderWindow *window, first_menu_t *main_menu)
{
	int n = 0;
	sfEvent event;

	while (n == 0) {
		while (sfRenderWindow_pollEvent(window, &event))
			n = help_event(event);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, main_menu->sprite[13], NULL);
		sfRenderWindow_display(window);
	}
	return (0);
}

void check_mouse_click(first_menu_t *main_menu, sfRenderWindow *window,
	sfEvent event, elem elem)
{
	sfVector2i position = {event.mouseButton.x, event.mouseButton.y};

	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 550 && position.y <= 610) {
			sfRenderWindow_close(window);
		}
	}
	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 350 && position.y <= 410)
			select_my_chicken(main_menu, window, elem);
	}
	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 450 && position.y <= 510)
			settings_main_menu(main_menu, window);
	}
	if (position.x >= 0 && position.x <= 300) {
		if (position.y >= 0 && position.y <= 60)
			display_help(window, main_menu);
	}
}

void check_cursor_click_second(first_menu_t *main_menu, sfRenderWindow *window)
{
	sfVector2i position = sfMouse_getPositionRenderWindow(window);
	sfIntRect play = {0, 0, 300, 60};
	sfIntRect color = {300, 0, 300, 60};

	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 550 && position.y <= 610)
			sfSprite_setTextureRect(main_menu->sprite[3], color);
		else
			sfSprite_setTextureRect(main_menu->sprite[3], play);
	} else
		sfSprite_setTextureRect(main_menu->sprite[3], play);
	if (position.x >= 0 && position.x <= 300) {
		if (position.y >= 0 && position.y <= 60)
			sfSprite_setTextureRect(main_menu->sprite[12], color);
		else
			sfSprite_setTextureRect(main_menu->sprite[12], play);
	} else
		sfSprite_setTextureRect(main_menu->sprite[12], play);
}

void check_cursor_click(first_menu_t *main_menu, sfRenderWindow *window)
{
	sfVector2i position = sfMouse_getPositionRenderWindow(window);
	sfIntRect play = {0, 0, 300, 60};
	sfIntRect color = {300, 0, 300, 60};

	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 350 && position.y <= 410)
			sfSprite_setTextureRect(main_menu->sprite[1], color);
		else
			sfSprite_setTextureRect(main_menu->sprite[1], play);
	} else
		sfSprite_setTextureRect(main_menu->sprite[1], play);
	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 450 && position.y <= 510)
			sfSprite_setTextureRect(main_menu->sprite[2], color);
		else
			sfSprite_setTextureRect(main_menu->sprite[2], play);
	} else
		sfSprite_setTextureRect(main_menu->sprite[2], play);
	check_cursor_click_second(main_menu, window);
}
