/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void load_the_burgers(game_t *game)
{
	sfVector2f resize_burger = {0.5, 0.5};
	sfVector2f move_burger = {-270, -160};

	if (game->burger == 1)
		game->texture[12] = sfTexture_createFromFile(
			"Assets/Sprites/Big_mac.png", NULL);
	if (game->burger == 2)
		game->texture[12] = sfTexture_createFromFile(
			"Assets/Sprites/Cheese_burger.png", NULL);
	if (game->burger == 3)
		game->texture[12] = sfTexture_createFromFile(
			"Assets/Sprites/Royal_burger.png", NULL);
	if (game->burger == 4)
		game->texture[12] = sfTexture_createFromFile(
			"Assets/Sprites/Simple_burger.png", NULL);
	sfSprite_setTexture(game->sprite[12], game->texture[12], sfTrue);
	sfSprite_setScale(game->sprite[12], resize_burger);
	sfSprite_setPosition(game->sprite[12], move_burger);
}

void load_game_text(game_t *game)
{
	sfVector2f move = {1390, 5};
	sfVector2f reduce = {0.75, 1};

	sfSprite_setScale(game->sprite[14], reduce);
	sfSprite_setPosition(game->sprite[14], move);
}

void load_game_assets(menu_t *menu, game_t *game, score_t *score)
{
	game->string[0] = 48;
	game->rect.left = 0;
	game->rect.top = 0;
	game->rect.width = 480;
	game->rect.height = 39;
	game->n = 1;
	charge_game_assets(menu, game);
	give_assets_position(game);
	game->clock = sfClock_create();
	game->time = sfClock_getElapsedTime(game->clock);
	game->second = game->time.microseconds / 1000000.0;
	game->rect.left = 0;
	sfSprite_setTextureRect(game->sprite[11], game->rect);
	game->sprite[12] = sfSprite_create();
	load_the_burgers(game);
	prepare_my_score(score);
	game->level = 10000000;
	load_game_text(game);
}