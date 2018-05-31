/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static void move_pictures2(menu_t *menu)
{
	sfVector2f move_buttonQuit = {750, 600};
	sfVector2f move_buttonVolume = {520, 500};
	sfVector2f move_buttonMinus = {430, 503};
	sfVector2f move_buttonPlus = {1373, 503};

	sfSprite_setPosition(menu->sprite[7], move_buttonMinus);
	sfSprite_setPosition(menu->sprite[6], move_buttonPlus);
	sfSprite_setPosition(menu->sprite[3], move_buttonQuit);
	sfSprite_setPosition(menu->sprite[4], move_buttonVolume);
	sfSprite_setPosition(menu->sprite[5], move_buttonQuit);
}

void move_pictures(menu_t *menu)
{
	sfVector2f resize_button = {1.2, 1.1};
	sfVector2f resize_background = {1, 1};
	sfVector2f resize_buttonVolume = {0.5, 0.5};
	sfVector2f move_buttonPlay = {750, 400};
	sfVector2f move_buttonSettings = {750, 500};

	sfSprite_setScale(menu->sprite[0], resize_background);
	sfSprite_setScale(menu->sprite[1], resize_button);
	sfSprite_setScale(menu->sprite[2], resize_button);
	sfSprite_setScale(menu->sprite[3], resize_button);
	sfSprite_setScale(menu->sprite[5], resize_button);
	sfSprite_setScale(menu->sprite[7], resize_buttonVolume);
	sfSprite_setScale(menu->sprite[6], resize_buttonVolume);
	sfSprite_setScale(menu->sprite[8], resize_button);
	sfSprite_setPosition(menu->sprite[1], move_buttonPlay);
	sfSprite_setPosition(menu->sprite[2], move_buttonSettings);
	sfSprite_setPosition(menu->sprite[8], move_buttonPlay);
	move_pictures2(menu);
}

int set_menu(sfRenderWindow *window, menu_t *menu)
{
	sfRenderWindow_setFramerateLimit(window, 60);
	char **res = char_array();

	for (int i = 0; i < 9; i++) {
		menu->texture[i] = sfTexture_createFromFile(res[i], NULL);
		if (!menu->texture[i])
			return (84);
		menu->sprite[i] = sfSprite_create();
		sfSprite_setTexture(menu->sprite[i], menu->texture[i], sfTrue);
	}
	if (load_song(menu) == 84)
		return (84);
	declare_string(menu);
	move_pictures(menu);
	return (0);
}

void initialise_burger(game_t *game)
{
	char *res = "Assets/Sprites/Transparent.png";

	for (int i = 0; i < 11; i++) {
		game->texture[i] = sfTexture_createFromFile(res, NULL);
		sfSprite_setTexture(game->sprite[i], game->texture[i], sfTrue);
	}
	game->n = 1;
	game->rect.left = 0;
	sfClock_restart(game->clock);
	reboot_string(game);
}

int charge_game_assets(menu_t *menu, game_t *game)
{
	char *res = "Assets/Sprites/Transparent.png";

	menu->texture[0] = sfTexture_createFromFile("Assets/Sprites/BG.png",
		NULL);
	sfSprite_setTexture(menu->sprite[0], menu->texture[0], sfTrue);
	for (int i = 1; i < 11; i++) {
		game->texture[i] = sfTexture_createFromFile(res, NULL);
		if (!game->texture)
			return (84);
		game->sprite[i] = sfSprite_create();
		sfSprite_setTexture(game->sprite[i], game->texture[i], sfTrue);
	}
	charge_game_assets2(game);
	return (0);
}