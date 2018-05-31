/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int load_song(menu_t *menu)
{
	menu->music = sfMusic_createFromFile("Assets/song/song.ogg");
	if (!menu->music)
		return (84);
	sfMusic_play(menu->music);
	sfMusic_setVolume(menu->music, 28);
	menu->click = sfMusic_createFromFile("Assets/song/click.ogg");
	if (!menu->click)
		return (84);
	sfMusic_play(menu->click);
	sfMusic_pause(menu->click);
	return (0);
}