/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/

#include "my.h"

void display_pictures(sfRenderWindow *window, menu_t *menu)
{
	sfRenderWindow_drawSprite(window, menu->sprite[0], NULL);
	sfRenderWindow_drawSprite(window, menu->sprite[1], NULL);
	sfRenderWindow_drawSprite(window, menu->sprite[2], NULL);
	sfRenderWindow_drawSprite(window, menu->sprite[3], NULL);
}

void display_game_assets(game_t *game, menu_t *menu, sfRenderWindow *window,
	score_t *score
)
{
	char *nombre = malloc(sizeof(char) * 20);
	char *burger = malloc(sizeof(char) * 20);

	sfRenderWindow_drawSprite(window, menu->sprite[0], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[14], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[0], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[1], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[2], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[3], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[4], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[5], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[6], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[7], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[8], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[9], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[10], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[11], NULL);
	sfRenderWindow_drawSprite(window, game->sprite[12], NULL);
	do_conv(score->score, &nombre);
	if (score->burger <= 0) {
		burger[0] = '0';
		burger[1] = '\0';
	} else
		do_conv(score->burger, &burger);
	screen_score(score, nombre, window, burger);
	do_move(game, score);
}

void destroy_things(menu_t *menu)
{
	sfSprite_destroy(menu->sprite[0]);
	sfTexture_destroy(menu->texture[0]);
	sfSprite_destroy(menu->sprite[1]);
	sfTexture_destroy(menu->texture[1]);
	sfSprite_destroy(menu->sprite[3]);
	sfSprite_destroy(menu->sprite[2]);
	sfTexture_destroy(menu->texture[2]);
	sfTexture_destroy(menu->texture[3]);
	sfSprite_destroy(menu->sprite[4]);
	sfTexture_destroy(menu->texture[4]);
	sfMusic_destroy(menu->click);
	sfMusic_destroy(menu->music);
}
