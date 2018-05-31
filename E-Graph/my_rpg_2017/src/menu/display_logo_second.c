/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"

void prepare_image_second(loading_screen_t *load, sfColor *color)
{
	load->sprite[2] = sfSprite_create();
	sfSprite_setTexture(load->sprite[2], load->texture[2], sfTrue);
	color->r = 255;
	color->g = 255;
	color->b = 255;
	color->a = 255;
	sfSprite_setColor(load->sprite[1], *color);
}