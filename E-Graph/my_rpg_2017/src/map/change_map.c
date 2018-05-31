/*
** EPITECH PROJECT, 2018
** change_map
** File description:
** changes map
*/

#include "my.h"

void check_spawn(elem *elem, sfVector2f pos)
{
	sfVector2f pos_up = {1044, 80};

	if (pos.y > 735)
		change_room(elem, pos_up, KITCHEN);
}

void check_warehouse(elem *elem, sfVector2f pos)
{
	sfVector2f pos_left = {168, 404};

	if (pos.x > 1378)
		change_room(elem, pos_left, KITCHEN);
}

void check_kitchen(elem *elem, sfVector2f pos)
{
	sfVector2f room_pos[] = {
		{1360, 484},
		{168, 644},
		{884, 720},
		{324, 8}
	};

	if (pos.x < 146)
		change_room(elem, room_pos[0], WAREHOUSE);
	if (pos.x > 1698)
		change_room(elem, room_pos[1], CAFET);
	if (pos.y < 75)
		change_room(elem, room_pos[2], SPAWN);
	if (pos.y > 735)
		change_room(elem, room_pos[3], HALL);
}

void check_cafet(elem *elem, sfVector2f pos)
{
	sfVector2f pos_right = {1680, 564};

	if (pos.x < 146)
		change_room(elem, pos_right, KITCHEN);
}

void check_hall(elem *elem, sfVector2f pos)
{
	sfVector2f pos_down = {724, 720};

	if (pos.y < -5 && pos.x < 640)
		change_room(elem, pos_down, KITCHEN);
}
