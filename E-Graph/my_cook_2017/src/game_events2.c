/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void event_top_bread(game_t *game)
{
	sfVector2f coord = sfSprite_getPosition(game->sprite[game->n - 1]);

	game->texture[game->n] = sfTexture_createFromFile(
		"Assets/Sprites/Pain_H.png", NULL);
	sfSprite_setTexture(game->sprite[game->n], game->texture[game->n],
		sfTrue);
	if (game->n != 1) {
		coord.y -= 100;
		sfSprite_setPosition(game->sprite[game->n], coord);
	}
	game->string[game->n] = 't';
	game->n++;
}

void event_bottom_bread(game_t *game)
{
	sfVector2f coord = sfSprite_getPosition(game->sprite[game->n - 1]);

	game->texture[game->n] = sfTexture_createFromFile(
		"Assets/Sprites/Pain_B.png", NULL);
	sfSprite_setTexture(game->sprite[game->n], game->texture[game->n],
		sfTrue);
	if (game->n != 1) {
		coord.y -= 30;
		sfSprite_setPosition(game->sprite[game->n], coord);
	}
	game->string[game->n] = 'g';
	game->n++;
}

int check_the_burgers(char *recipe, game_t *game)
{
	int n = 1;
	if (my_strlen(game->string) != my_strlen(recipe))
		return (2);
	while (recipe[n] != '\0' && game->string[n] != '\0') {
		if (recipe[n] != game->string[n])
			return (2);
		n++;
	}
	return (1);
}

void check_if_same(game_t *game, score_t *score)
{
	int n = 0;

	if (game->burger == 1)
		n = check_the_burgers("0gzragzat\0", game);
	if (game->burger == 2)
		n = check_the_burgers("0grart\0", game);
	if (game->burger == 3)
		n = check_the_burgers("0garezt\0", game);
	if (game->burger == 4)
		n = check_the_burgers("0gaet\0", game);
	do_the_new_recipe(game, n, score);
}

void look_for_other(game_t *game, sfEvent *event, score_t *score)
{
	if (event->key.code == sfKeyB && game->n >= 2) {
		game->n--;
		game->texture[game->n] = sfTexture_createFromFile(
			"Assets/Sprites/Transparent.png", NULL);
		sfSprite_setTexture(game->sprite[game->n],
			game->texture[game->n], sfTrue);
		game->string[game->n] = '\0';
	} else if (event->key.code == sfKeyReturn)
		check_if_same(game, score);
}
