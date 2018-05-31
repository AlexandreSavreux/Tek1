/*
** EPITECH PROJECT, 2018
** stats
** File description:
** stats manage
*/

#include "my.h"

void display_stats_numbers(sfRenderWindow *window, stats stats)
{
	sfVector2f pos[] = {{1036, 694}, {830, 385}, {830, 513}};
	int size[] = {35, 90, 90};
	int nb[] = {stats.level, stats.life, stats.power};

	for (int i = 0; i < 3; i++) {
		sfText_setCharacterSize(stats.text, size[i]);
		sfText_setPosition(stats.text, pos[i]);
		int_sfText(stats.text, nb[i]);
		sfRenderWindow_drawText(window, stats.text, NULL);
	}
}

void display_stats(sfRenderWindow *window, stats stats)
{
	if (stats.active == sfTrue) {
		sfRenderWindow_drawSprite(window, stats.sprite[MENU], NULL);
		sfRenderWindow_drawSprite(window, stats.sprite[CHICKEN], NULL);
		display_stats_numbers(window, stats);
		if (stats.xp == 50)
			sfRenderWindow_drawSprite(window, stats.sprite[XP],
						NULL);
	}
}

void check_stats(elem *elem)
{
	int nb = 0;

	for (int i = 0;	i < NB_ROOMS; i++) {
		if (elem->pnj[0].hp[i] <= 0)
			nb++;
		if (elem->pnj[1].hp[i] <= 0)
			nb++;
	}
	elem->stats.xp = nb * 50 % 100;
	elem->stats.level = 1 + nb / 2;
	elem->stats.power = elem->stats.level * 25;
}
