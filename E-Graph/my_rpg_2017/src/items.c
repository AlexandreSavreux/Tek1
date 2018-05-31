/*
** EPITECH PROJECT, 2018
** items
** File description:
** manages pickupable items
*/

#include "my.h"

int create_items(pickup_items *items)
{
	sfVector2f pos[] = {{720, 320}, {900, 325}, {1040, 555}};
	char *texture[] = {"assets/textures/items/pickup_items/knife.png",
			"assets/textures/items/pickup_items/rocket.png",
			"assets/textures/items/pickup_items/ak47.png"};

	for (int i = 0; i < 3; i++) {
		items->texture[i] = sfTexture_createFromFile(texture[i], NULL);
		if (!items->texture[i])
			return (0);
		items->sprite[i] = sfSprite_create();
		sfSprite_setTexture(items->sprite[i], items->texture[i],
				sfTrue);
		sfSprite_setPosition(items->sprite[i], pos[i]);
	}
	return (1);
}

void display_pickup_items(sfRenderWindow *window, pickup_items items, map room,
		inventory inv)
{
	switch (room) {
	case SPAWN:
		if (inv.item[KNIFE].nbr == 0)
			sfRenderWindow_drawSprite(window, items.sprite[KNIFE],
						NULL);
		break;
	case KITCHEN:
		if (inv.item[AK47].nbr == 0)
			sfRenderWindow_drawSprite(window, items.sprite[AK47],
						NULL);
		break;
	case HALL:
		if (inv.item[ROCKET].nbr == 0)
			sfRenderWindow_drawSprite(window, items.sprite[ROCKET],
						NULL);
		break;
	default:
		room = room;
	}
}
