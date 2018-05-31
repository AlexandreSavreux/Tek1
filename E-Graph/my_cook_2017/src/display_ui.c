/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void do_move(game_t *game, score_t *score)
{
	if (sfClock_getElapsedTime(game->clock).microseconds > game->level) {
		if (game->rect.left == 7200) {
			game->rect.left = 0;
			score->score -= 500;
			initialise_burger(game);
			set_menu_play(game);
			load_the_burgers(game);
		} else
			game->rect.left += 480;
		sfClock_restart(game->clock);
	}
	sfSprite_setTextureRect(game->sprite[11], game->rect);
}

void do_the_new_recipe(game_t *game, int n, score_t *score)
{
	if (n == 1) {
		score->score += 200;
		score->burger++;
		game->level = game->level * 0.8775654568676976655409870987;
	}
	if (n == 2) {
		score->score -= 500;
	}
	initialise_burger(game);
	set_menu_play(game);
	load_the_burgers(game);
}

int do_settings(sfRenderWindow *window, menu_t *menu)
{
	int n = 0;
	sfEvent myEvent;

	while (n == 0) {
		change_button_settings(menu);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, menu->sprite[0], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[5], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[4], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[7], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[6], NULL);
		sfRenderWindow_display(window);
		while (sfRenderWindow_pollEvent(window, &myEvent))
			n = analyse_settings(myEvent, menu);
	}
	return (0);
}

void do_pause(int *n, sfRenderWindow *window, menu_t *menu)
{
	int i = 0;
	sfEvent event;

	while (i == 0) {
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, menu->sprite[0], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[5], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[8], NULL);
		sfRenderWindow_drawSprite(window, menu->sprite[3], NULL);
		sfRenderWindow_display(window);
		while (sfRenderWindow_pollEvent(window, &event))
			analyse_pause(event, n, &i, window, menu);
	}
}