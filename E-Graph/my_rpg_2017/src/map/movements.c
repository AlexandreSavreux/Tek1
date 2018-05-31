/*
** EPITECH PROJECT, 2018
** movements
** File description:
** manages movements, animations...
*/

#include <stdio.h>
#include "my.h"

int move_sprite(sfVector2f v, elem *elem)
{
	int i = 0;
	sfVector2f pos = sfSprite_getPosition(elem->chicken);
	sfIntRect rect = {pos.x + 14 + v.x, pos.y + 5 + v.y, 48, 60};

	while (i < elem->map[elem->room].nb_blocks) {
		if (sfIntRect_intersects(&rect, &elem->map[elem->room].block[i],
			NULL) == sfTrue)
			return (0);
		i++;
	}
	sfSprite_move(elem->chicken, v);
	return (1);
}

int move_chick(elem *elem, sfKeyCode key, sfVector2f v, int top)
{
	sfIntRect rect = sfSprite_getTextureRect(elem->chicken);

	if (sfKeyboard_isKeyPressed(key)) {
		rect.top = top;
		sfSprite_setTextureRect(elem->chicken, rect);
		move_sprite(v, elem);
		move_sprite(v, elem);
		if (sfKeyboard_isKeyPressed(sfKeyLShift) ||
			sfKeyboard_isKeyPressed(sfKeyRShift)) {
			move_sprite(v, elem);
			move_sprite(v, elem);
		}
		return (1);
	}
	return (0);
}

void move_rect(sfSprite *chicken, int color)
{
	sfIntRect rect = sfSprite_getTextureRect(chicken);

	if (rect.left == 216 + 288 * color)
		rect.left = 288 * color;
	else
		rect.left += 72;
	sfSprite_setTextureRect(chicken, rect);
}

void chicken_movements(elem *elem)
{
	sfVector2f v[] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
	int top[] = {216, 0, 144, 72};
	sfKeyCode key[] = {sfKeyUp, sfKeyDown, sfKeyRight, sfKeyLeft};
	int j = 0;
	sfIntRect rect;

	for (int i = 0; i < 4; i++)
		if (move_chick(elem, key[i], v[i], top[i]) == 1)
			j = 1;
	rect = sfSprite_getTextureRect(elem->chicken);
	rect.left = 72 + 288 * elem->stats.color;
	if (sfClock_getElapsedTime(elem->chicken_clock).microseconds > 200000
	&& j == 1) {
		move_rect(elem->chicken, elem->stats.color);
		sfClock_restart(elem->chicken_clock);
	}
	if (j == 0)
		sfSprite_setTextureRect(elem->chicken, rect);
}

void move_chicken(elem *elem)
{
	if (elem->inv.active == sfFalse &&
	elem->inv.user.item[KNIFE].weapon[WEAPON].active == sfFalse
	&& elem->stats.active == sfFalse &&
	elem->quest.active == sfFalse)
		chicken_movements(elem);
}
