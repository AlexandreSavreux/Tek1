/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

int prepare_image(loading_screen_t *load, sfColor *color)
{
	char *textures[] = {"assets/textures/menu/main_menu/doublea.png",
			"assets/textures/menu/main_menu/black.jpg"};
	char *musics[] = {"assets/audio/intro.ogg",
			"assets/audio/mbgesong.ogg"};

	for (int i = 0;	i < 2; i++) {
		load->music[i] = sfMusic_createFromFile(musics[i]);
		load->texture[i] = sfTexture_createFromFile(textures[i], NULL);
		if (!load->music[i] || !load->texture[i])
			return (84);
		load->sprite[i] = sfSprite_create();
		sfSprite_setTexture(load->sprite[i], load->texture[i], sfTrue);
	}
	load->texture[2] = sfTexture_createFromFile
		("assets/textures/menu/main_menu/mbge.png", NULL);
	if (!load->texture[2])
		return (84);
	prepare_image_second(load, color);
	return (0);
}

void destroy_load_screen(loading_screen_t *load)
{
	sfTexture_destroy(load->texture[0]);
	sfSprite_destroy(load->sprite[0]);
	sfTexture_destroy(load->texture[1]);
	sfSprite_destroy(load->sprite[1]);
	sfTexture_destroy(load->texture[2]);
	sfSprite_destroy(load->sprite[2]);
	sfMusic_destroy(load->music[0]);
	sfMusic_destroy(load->music[1]);
}

void display_second_logo(loading_screen_t *load, sfColor *color,
	sfRenderWindow *window)
{
	sfMusic_play(load->music[1]);
	while (color->a != 0) {
		sfSprite_setColor(load->sprite[1], *color);
		color->a--;
		sfRenderWindow_clear(window, sfWhite);
		sfRenderWindow_drawSprite(window, load->sprite[2], NULL);
		sfRenderWindow_drawSprite(window, load->sprite[1], NULL);
		sfRenderWindow_display(window);
	}
	sfSleep(sfSeconds(1.5));
	while (color->a != 255) {
		sfSprite_setColor(load->sprite[1], *color);
		color->a++;
		sfRenderWindow_clear(window, sfWhite);
		sfRenderWindow_drawSprite(window, load->sprite[2], NULL);
		sfRenderWindow_drawSprite(window, load->sprite[1], NULL);
		sfRenderWindow_display(window);
	}
}

void display_first_logo(loading_screen_t *load, sfColor *color,
	sfRenderWindow *window)
{
	sfMusic_play(load->music[0]);
	while (color->a != 0) {
		sfSprite_setColor(load->sprite[1], *color);
		color->a--;
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, load->sprite[0], NULL);
		sfRenderWindow_drawSprite(window, load->sprite[1], NULL);
		sfRenderWindow_display(window);
	}
	sfSleep(sfSeconds(1.5));
	while (color->a != 255) {
		sfSprite_setColor(load->sprite[1], *color);
		color->a++;
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, load->sprite[0], NULL);
		sfRenderWindow_drawSprite(window, load->sprite[1], NULL);
		sfRenderWindow_display(window);
	}
}

int display_logo(sfRenderWindow *window)
{
	loading_screen_t load;
	sfColor color;

	if (prepare_image(&load, &color) == 84)
		return (84);
	display_first_logo(&load, &color, window);
	display_second_logo(&load, &color, window);
	destroy_load_screen(&load);
	return (0);
}
