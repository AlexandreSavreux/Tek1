/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include "my.h"

int check_time_ak47(damage *damage)
{
	if (sfClock_getElapsedTime(damage->clock_ak).microseconds >
		150000) {
		sfClock_restart(damage->clock_ak);
		return (0);
	}
	return (1);
}

int check_time_rocket(damage *damage)
{
	if (sfClock_getElapsedTime(damage->clock_rocket).microseconds >
		250000) {
		sfClock_restart(damage->clock_rocket);
		return (0);
	}
	return (1);
}

int check_time_knife(damage *damage)
{
	if (sfClock_getElapsedTime(damage->clock_cut).microseconds > 250000) {
		sfClock_restart(damage->clock_cut);
		return (0);
	}
	return (1);
}