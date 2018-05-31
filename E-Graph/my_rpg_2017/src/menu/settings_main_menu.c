/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

void display_settings(first_menu_t *main_menu, sfRenderWindow *window)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, main_menu->sprite[0], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[8], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[9], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[10], NULL);
	sfRenderWindow_drawSprite(window, main_menu->sprite[11], NULL);
	sfRenderWindow_display(window);
}

void check_event_position_second(sfEvent event, first_menu_t *main_menu)
{
	sfVector2i position = {event.mouseButton.x, event.mouseButton.y};

	if (position.x >= 1247 && position.x <= 1415 &&
		main_menu->volume != 40) {
		if (position.y >= 550 && position.y <= 650) {
			main_menu->volume += 10;
			main_menu->song.left += 500;
			sfSprite_setTextureRect(main_menu->sprite[9],
				main_menu->song);
			sfMusic_setVolume(main_menu->music[0],
				main_menu->volume);
		}
	}
}

int check_event_position(sfEvent event, first_menu_t *main_menu)
{
	sfVector2i position = {event.mouseButton.x, event.mouseButton.y};

	if (position.x >= 810 && position.x <= 1110) {
		if (position.y >= 700 && position.y <= 760)
			return (1);
	}
	if (position.x >= 500 && position.x <= 670 && main_menu->volume != 0) {
		if (position.y >= 550 && position.y <= 650) {
			main_menu->volume -= 10;
			main_menu->song.left -= 500;
			sfSprite_setTextureRect(main_menu->sprite[9],
				main_menu->song);
			sfMusic_setVolume(main_menu->music[0],
				main_menu->volume);
			return (0);
		}
	}
	check_event_position_second(event, main_menu);
	return (0);
}

int check_settings_event(sfEvent event, first_menu_t *main_menu)
{
	int n = 0;

	if (event.type == sfEvtMouseButtonPressed) {
		n = check_event_position(event, main_menu);
		if (n == 1)
			return (1);
	}
	if (event.key.code == sfKeyEscape)
		return (1);
	return (0);
}

int settings_main_menu(first_menu_t *main_menu, sfRenderWindow *window)
{
	sfEvent event;
	int n = 0;

	while (n == 0) {
		while (sfRenderWindow_pollEvent(window, &event))
			n = check_settings_event(event, main_menu);
		change_button(main_menu, window);
		display_settings(main_menu, window);
	}
	return (0);
}
