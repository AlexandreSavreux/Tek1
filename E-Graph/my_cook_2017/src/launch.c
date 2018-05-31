/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void set_menu_play(game_t *game)
{
	game->burger = rand() % 4 + 1;
}

void give_assets_position(game_t *game)
{
	sfVector2f move_inventory = {0, -25};
	sfVector2f move_first_one = {700, 750};

	sfSprite_setPosition(game->sprite[0], move_inventory);
	sfSprite_setPosition(game->sprite[1], move_first_one);
}

int play_game(sfRenderWindow *window, menu_t *menu)
{
	int n = 1;
	sfEvent event;
	game_t game;
	score_t score;

	set_menu_play(&game);
	load_game_assets(menu, &game, &score);
	while (n == 1) {
		sfRenderWindow_clear(window, sfBlack);
		display_game_assets(&game, menu, window, &score);
		sfRenderWindow_display(window);
		while (sfRenderWindow_pollEvent(window, &event)) {
			analyse_game(event, &n, window, menu);
			event_burger(&event, &game, &score);
		}
		if (score.score <= 0)
			n = 0;
	}
	if (score.score <= 0)
		display_game_over(&game, window);
	return (0);
}

int do_game(void)
{
	menu_t menu;
	sfVideoMode mode = {1920, 1080, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "my_cook",
		sfResize | sfClose, NULL);
	sfEvent event;

	if (set_menu(window, &menu) == 84)
		return (84);
	while (sfRenderWindow_isOpen(window)) {
		change_button(&menu);
		while (sfRenderWindow_pollEvent(window, &event))
			analyse_events(event, window, &menu);
		sfRenderWindow_clear(window, sfBlack);
		display_pictures(window, &menu);
		sfRenderWindow_display(window);
	}
	destroy_things(&menu);
	sfRenderWindow_destroy(window);
	return (0);
}
