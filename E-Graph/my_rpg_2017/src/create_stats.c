/*
** EPITECH PROJECT, 2018
** create_stats
** File description:
** creates stats struct
*/

#include "my.h"

int create_stats(stats *stats)
{
	char *textures[] = {"assets/textures/stats/chicken.png",
	"assets/textures/stats/stats.png", "assets/textures/stats/xp.png"};
	sfVector2f pos[] = {{758, 189}, {600, 100}, {637, 705}};

	for (int i = 0; i < 3; i++) {
		stats->texture[i] = sfTexture_createFromFile(textures[i], NULL);
		if (!stats->texture[i])
			return (0);
		stats->sprite[i] = sfSprite_create();
		sfSprite_setTexture(stats->sprite[i], stats->texture[i],
				sfTrue);
		sfSprite_setPosition(stats->sprite[i], pos[i]);
	}
	stats->font = sfFont_createFromFile("assets/font/font.ttf");
	if (!stats->font)
		return (0);
	stats->text = sfText_create();
	sfText_setFont(stats->text, stats->font);
	sfText_setColor(stats->text, sfBlack);
	return (1);
}
