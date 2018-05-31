/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void display_game_over(game_t *game, sfRenderWindow *window)
{
	sfVector2f middle = {300, 400};
	sfVector2f bigger = {4, 4};

	sfSprite_setPosition(game->sprite[13], middle);
	sfSprite_setScale(game->sprite[13], bigger);
	sfClock_restart(game->clock);
	while (sfClock_getElapsedTime(game->clock).microseconds < 3000000) {
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, game->sprite[13], NULL);
		sfRenderWindow_display(window);
	}
}

void check_click(sfEvent event, sfRenderWindow *window, menu_t *menu)
{
	sfVector2f position = {(float)event.mouseButton.x,
		(float)event.mouseButton.y};

	if (position.x >= 750 && position.x <= 1110) {
		if (position.y >= 600 && position.y <= 660) {
			sfMusic_play(menu->click);
			sfRenderWindow_close(window);
		}
	}
	if (position.x >= 750 && position.x <= 1110) {
		if (position.y >= 500 && position.y <= 560) {
			sfMusic_play(menu->click);
			do_settings(window, menu);
		}
	}
	if (position.x >= 750 && position.x <= 1110) {
		if (position.y >= 400 && position.y <= 460) {
			sfMusic_play(menu->click);
			play_game(window, menu);
			menu->texture[0] = sfTexture_createFromFile(
				"Assets/Sprites/menu.jpg", NULL);
			sfSprite_setTexture(menu->sprite[0], menu->texture[0],
				sfTrue);
		}
	}
}

void analyse_events(sfEvent event, sfRenderWindow *window, menu_t *menu)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event.type == sfEvtMouseButtonReleased)
		check_click(event, window, menu);
}