/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

void move_my_chicken(first_menu_t *main_menu, clock_d *hour, sfIntRect *rect)
{
	if (sfClock_getElapsedTime(hour->clock).microseconds > 250000) {
		if (rect->left == 216)
			rect->left = 0;
		else
			rect->left += 72;
		sfClock_restart(hour->clock);
	}
	sfSprite_setTextureRect(main_menu->sprite[4], *rect);
}

int check_my_event_third(sfEvent event, first_menu_t *main_menu, elem elem,
	sfIntRect rect)
{
	sfVector2i position = sfMouse_getPositionRenderWindow(elem.window);

	color_button_play_select(main_menu, elem);
	if (event.type == sfEvtMouseButtonPressed) {
		if (position.x >= 810 && position.x <= 1110 &&
			position.y >= 700 && position.y <= 760) {
			elem.stats.color = rect.top / 72;
			sfRenderWindow_setMouseCursorVisible
				(elem.window, sfFalse);
			rpg(elem);
			return (1);
		}
	}
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyReturn) {
		elem.stats.color = rect.top / 72;
		sfRenderWindow_setMouseCursorVisible(elem.window, sfFalse);
		rpg(elem);
		return (1);
	}
	return (0);
}

int check_my_event_second(sfEvent event, sfIntRect *rect,
	first_menu_t *main_menu, elem elem)
{
	if (event.type == sfEvtMouseButtonPressed &&
		(event.mouseButton.x >= 1060 && event.mouseButton.x <= 1220) &&
		(event.mouseButton.y >= 490 && event.mouseButton.y <= 590)) {
		if (rect->top == 504)
			rect->top = 0;
		else
			rect->top += 72;
	}
	if (event.type == sfEvtMouseButtonPressed &&
		(event.mouseButton.x >= 700 && event.mouseButton.x <= 870) &&
		(event.mouseButton.y >= 490 && event.mouseButton.y <= 590)) {
		if (rect->top == 0)
			rect->top = 504;
		else
			rect->top -= 72;
	}
	return (check_my_event_third(event, main_menu, elem, *rect));
}

int check_my_event(sfEvent event, sfIntRect *rect, first_menu_t *main_menu,
	elem elem)
{
	if (event.type == sfEvtKeyPressed &&
		(event.key.code == sfKeyD || event.key.code == sfKeyRight)) {
		if (rect->top == 504)
			rect->top = 0;
		else
			rect->top += 72;
	}
	if (event.type == sfEvtKeyPressed &&
		(event.key.code == sfKeyQ || event.key.code == sfKeyLeft)) {
		if (rect->top == 0)
			rect->top = 504;
		else
			rect->top -= 72;
	}
	if (event.key.code == sfKeyEscape)
		return (1);
	if (event.mouseButton.x >= 810 && event.mouseButton.x <= 1110 &&
	event.mouseButton.y >= 780 && event.mouseButton.y <= 840)
		return (1);
	return (check_my_event_second(event, rect, main_menu, elem));
}

void select_my_chicken(first_menu_t *main_menu, sfRenderWindow *window,
		elem elem)
{
	clock_d hour;
	sfEvent event;
	sfIntRect rect = {0, 0, 72, 72};
	int n = 0;

	prepare_screen(&hour, main_menu);
	while (n == 0 && sfRenderWindow_isOpen(elem.window)) {
		while (sfRenderWindow_pollEvent(window, &event))
			n = check_my_event(event, &rect, main_menu, elem);
		move_my_chicken(main_menu, &hour, &rect);
		display_my_chicken(main_menu, window);
	}
	sfClock_destroy(hour.clock);
}
