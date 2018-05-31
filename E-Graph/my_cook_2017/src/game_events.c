/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void event_cheese(game_t *game)
{
	sfVector2f coord = sfSprite_getPosition(game->sprite[game->n - 1]);

	game->texture[game->n] = sfTexture_createFromFile(
		"Assets/Sprites/Fromage.png", NULL);
	sfSprite_setTexture(game->sprite[game->n], game->texture[game->n],
		sfTrue);
	if (game->n != 1) {
		coord.y -= 15;
		sfSprite_setPosition(game->sprite[game->n], coord);
	}
	game->string[game->n] = 'r';
	game->n++;
}

void event_salad(game_t *game)
{
	sfVector2f coord = sfSprite_getPosition(game->sprite[game->n - 1]);

	game->texture[game->n] = sfTexture_createFromFile(
		"Assets/Sprites/Salade.png", NULL);
	sfSprite_setTexture(game->sprite[game->n], game->texture[game->n],
		sfTrue);
	if (game->n != 1) {
		coord.y -= 70;
		sfSprite_setPosition(game->sprite[game->n], coord);
	}
	game->string[game->n] = 'z';
	game->n++;
}

void event_steak(game_t *game)
{
	sfVector2f coord = sfSprite_getPosition(game->sprite[game->n - 1]);

	game->texture[game->n] = sfTexture_createFromFile(
		"Assets/Sprites/Steak.png", NULL);
	sfSprite_setTexture(game->sprite[game->n], game->texture[game->n],
		sfTrue);
	if (game->n != 1) {
		coord.y -= 30;
		sfSprite_setPosition(game->sprite[game->n], coord);
	}
	game->string[game->n] = 'a';
	game->n++;
}

void event_tomato(game_t *game)
{
	sfVector2f coord = sfSprite_getPosition(game->sprite[game->n - 1]);

	game->texture[game->n] = sfTexture_createFromFile(
		"Assets/Sprites/Tomate.png", NULL);
	sfSprite_setTexture(game->sprite[game->n], game->texture[game->n],
		sfTrue);
	if (game->n != 1) {
		coord.y -= 30;
		sfSprite_setPosition(game->sprite[game->n], coord);
	}
	game->string[game->n] = 'e';
	game->n++;
}

void event_burger(sfEvent *event, game_t *game, score_t *score)
{
	if (event->type == sfEvtKeyPressed) {
		if (event->key.code == sfKeyA && game->n <= 9)
			event_steak(game);
		else if (event->key.code == sfKeyZ && game->n <= 9)
			event_salad(game);
		else
			other_things(event, game, score);
	}
}