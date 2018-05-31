/*
** EPITECH PROJECT, 2022
** Display.c
** File description:
** Created by f.louvet,
*/
#include "struct.h"

void load_textures(void)
{
	sfIntRect rect_temp = {0, 0, 110, 110};

	assets_t.hitbox = rect_temp;
	assets_t.textures[0] = sfTexture_createFromFile(
		"resources/Assets/background.png", NULL);
	assets_t.sprites[0] = sfSprite_create();
	sfSprite_setTexture(assets_t.sprites[0], assets_t.textures[0], sfTrue);
	assets_t.textures[1] = sfTexture_createFromFile(
		"resources/Assets/spritesheet.png", NULL);
	assets_t.sprites[1] = sfSprite_create();
	sfSprite_setTexture(assets_t.sprites[1], assets_t.textures[1], sfTrue);
	sfSprite_setTextureRect(assets_t.sprites[1], assets_t.hitbox);
	assets_t.textures[2] = sfTexture_createFromFile(
		"resources/Assets/aim.png", NULL);
	assets_t.sprites[2] = sfSprite_create();
	sfSprite_setTexture(assets_t.sprites[2], assets_t.textures[2], sfTrue);
	load_miscs();
}

void destroyer(void)
{
	sfMusic_stop(assets_t.music);
	sfMusic_destroy(assets_t.music);
	sfSprite_destroy(assets_t.sprites[2]);
	sfSprite_destroy(assets_t.sprites[1]);
	sfSprite_destroy(assets_t.sprites[0]);
	sfTexture_destroy(assets_t.textures[2]);
	sfTexture_destroy(assets_t.textures[1]);
	sfTexture_destroy(assets_t.textures[0]);
}

void my_drawer(sfRenderWindow *window)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, assets_t.sprites[0], NULL);
	sfRenderWindow_drawSprite(window, assets_t.sprites[1], NULL);
	sfRenderWindow_drawSprite(window, assets_t.sprites[2], NULL);
	sfRenderWindow_display(window);
}