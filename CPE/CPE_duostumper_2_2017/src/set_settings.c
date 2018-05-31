/*
** EPITECH PROJECT, 2022
** CPE_duostumper_2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"
#include "struct.h"

int change_width(int value, setting_t *settings)
{
	if (value <= 0 || value > 80) {
		my_puterror("Invalid width\n");
		return (84);
	}
	settings->width = value;
	return (0);
}

int change_height(int value, setting_t *settings)
{
	if (value <= 0 || value > 16) {
		my_puterror("Invalid width\n");
		return (84);
	}
	settings->height = value;
	return (0);
}

int change_players_avatar(char *optn, char *value, setting_t *settings)
{
	if (!my_str_isprintable(value) && (optn[2]) != '1' && optn[2] != '2' ||
		value[0] == '.') {
		my_puterror("Invalid player avatar\n");
		return (84);
	}
	if (optn[2] == '1' && value[0] != settings->name_p2 &&
		value[0] != settings->finish)
		settings->name_p1 = value[0];
	else if (optn[2] == '2' && value[0] != settings->name_p1 &&
		value[0] != settings->finish)
		settings->name_p2 = value[0];
	else {
		my_puterror("Players avatar cannot be the same char and ");
		my_puterror("the same as referee\n");
		return (84);
	}
	return (0);
}

int change_referee(char *value, setting_t *settings)
{
	if (!my_str_isprintable(value) && value[0] == settings->name_p1 ||
		value[0] == settings->name_p2 || value[0] == '.') {
		my_puterror("Invalid referee\n");
		return (84);
	}
	settings->finish = value[0];
	return (0);
}