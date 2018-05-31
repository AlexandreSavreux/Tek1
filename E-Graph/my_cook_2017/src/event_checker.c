/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void another_things(sfEvent *event, game_t *game, score_t *score)
{
	if (event->key.code == sfKeyT && game->n <= 9)
		event_top_bread(game);
	else if (event->key.code == sfKeyG && game->n <= 9)
		event_bottom_bread(game);
	else
		look_for_other(game, event, score);
}

void other_things(sfEvent *event, game_t *game, score_t *score)
{
	if (event->key.code == sfKeyE && game->n <= 9)
		event_tomato(game);
	else if (event->key.code == sfKeyR && game->n <= 9)
		event_cheese(game);
	else
		another_things(event, game, score);
}

int analyse_settings(sfEvent event, menu_t *menu)
{
	int n = 0;

	if (event.type == sfEvtMouseButtonReleased)
		n = settings_click(event, menu);
	return (n);
}

void analyse_pause(sfEvent event, int *n, int *i, sfRenderWindow *window,
	menu_t *menu
)
{
	sfVector2f position = {(float)event.mouseButton.x,
		(float)event.mouseButton.y};
	if (event.type == sfEvtMouseButtonReleased) {
		if (check_pos(position, menu, n, i) == 42)
			do_settings(window, menu);
	}
}

void analyse_game(sfEvent event, int *n, sfRenderWindow *window, menu_t *menu)
{
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyEscape) {
			do_pause(n, window, menu);
		}
	}
}