/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** Created by Julien THUEUX
*/

#include "my.h"

void resize_asset_first_menu_third(first_menu_t *main_menu)
{
	sfVector2f move_play_chicken = {810, 700};
	sfVector2f move_back_chicken = {810, 780};
	sfVector2f move_song = {710, 200};
	sfVector2f move_left_arrow_settings = {500, 550};
	sfVector2f move_right_arrow_settings = {1250, 550};

	sfSprite_setPosition(main_menu->sprite[7], move_play_chicken);
	sfSprite_setPosition(main_menu->sprite[8], move_play_chicken);
	sfSprite_setPosition(main_menu->sprite[9], move_song);
	sfSprite_setPosition(main_menu->sprite[10], move_left_arrow_settings);
	sfSprite_setPosition(main_menu->sprite[11], move_right_arrow_settings);
	sfSprite_setPosition(main_menu->sprite[14], move_back_chicken);
}

void resize_asset_first_menu_second(first_menu_t *main_menu)
{
	sfVector2f play_position = {810, 350};
	sfVector2f settings_position = {810, 450};
	sfVector2f quit_position = {810, 550};
	sfVector2f move_left_arrow = {700, 488};
	sfVector2f move_right_arrow = {1060, 488};

	sfMusic_setVolume(main_menu->music[0], main_menu->volume);
	sfSprite_setPosition(main_menu->sprite[1], play_position);
	sfSprite_setPosition(main_menu->sprite[2], settings_position);
	sfSprite_setPosition(main_menu->sprite[3], quit_position);
	sfSprite_setPosition(main_menu->sprite[5], move_left_arrow);
	sfSprite_setPosition(main_menu->sprite[6], move_right_arrow);
	resize_asset_first_menu_third(main_menu);
}

void change_texture_rect(first_menu_t *main_menu, sfIntRect play)
{
	sfSprite_setTextureRect(main_menu->sprite[1], play);
	sfSprite_setTextureRect(main_menu->sprite[2], play);
	sfSprite_setTextureRect(main_menu->sprite[3], play);
	sfSprite_setTextureRect(main_menu->sprite[12], play);
	sfSprite_setTextureRect(main_menu->sprite[7], play);
	sfSprite_setTextureRect(main_menu->sprite[12], play);
	sfSprite_setTextureRect(main_menu->sprite[14], play);
	sfSprite_setTextureRect(main_menu->sprite[9], main_menu->song);
}

int resize_asset_first_menu(first_menu_t *main_menu)
{
	sfVector2f move_chicken = {888, 468};
	sfVector2f resize_chicken = {2, 2};
	sfIntRect play = {0, 0, 300, 60};
	sfIntRect rect = {1000, 0, 500, 450};

	main_menu->music[0] = sfMusic_createFromFile
		("assets/audio/menu_song.ogg");
	if (!main_menu->music[0])
		return (84);
	sfMusic_setLoop(main_menu->music[0], 1);
	main_menu->volume = 20;
	sfMusic_setVolume(main_menu->music[0], main_menu->volume);
	main_menu->song = rect;
	sfSprite_setScale(main_menu->sprite[4], resize_chicken);
	change_texture_rect(main_menu, play);
	sfSprite_setPosition(main_menu->sprite[4], move_chicken);
	resize_asset_first_menu_second(main_menu);
	return (0);
}
