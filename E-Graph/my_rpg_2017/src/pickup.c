/*
** EPITECH PROJECT, 2018
** pickup
** File description:
** pickup events functions
*/

#include "my.h"

void check_ak47(elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(elem->chicken);

	if (pos.x >= 1022 && pos.x <= 1070 && pos.y == 590
	&& sfSprite_getTextureRect(elem->chicken).top == 216)
		elem->inv.item[AK47].nbr = 1;
	if (pos.x >= 1022 && pos.x <= 1070 && pos.y == 495
	&& sfSprite_getTextureRect(elem->chicken).top == 0)
		elem->inv.item[AK47].nbr = 1;
}

void check_rocket_launcher(elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(elem->chicken);
	sfIntRect chicken = {pos.x, pos.y, 48, 60};
	sfIntRect rocket_launcher = {900, 325, 80, 80};

	if (sfIntRect_intersects(&chicken, &rocket_launcher, NULL))
		elem->inv.item[ROCKET].nbr = 1;
}

void check_knife(elem *elem)
{
	sfVector2f pos = sfSprite_getPosition(elem->chicken);

	if (pos.x >= 698 && pos.x <= 754 && pos.y == 350
	&& sfSprite_getTextureRect(elem->chicken).top == 216)
			elem->inv.item[KNIFE].nbr = 1;
}

void pickup_events(elem *elem, sfEvent event)
{
	if (event.key.code == sfKeyReturn) {
		if (elem->room == SPAWN && elem->inv.item[KNIFE].nbr == 0)
			check_knife(elem);
		if (elem->room == KITCHEN && elem->inv.item[AK47].nbr == 0)
			check_ak47(elem);
		if (elem->room == HALL && elem->inv.item[ROCKET].nbr == 0)
			check_rocket_launcher(elem);
	}
}
