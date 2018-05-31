/*
** EPITECH PROJECT, 2022
** Misc.c
** File description:
** Created by f.louvet,
*/
#include "struct.h"

void load_miscs(void)
{
	assets_t.music = sfMusic_createFromFile(
		"resources/Audio/main_theme.ogg");
	sfMusic_setLoop(assets_t.music, sfTrue);
	sfMusic_setVolume(assets_t.music, 20);
	sfMusic_play(assets_t.music);
	event_t.duck_speed.x = 10;
	event_t.respawn_pos.x = -110;
	event_t.respawn_pos.y = 0;
	assets_t.boole = 1;
}