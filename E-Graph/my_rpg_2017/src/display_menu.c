/*
** EPITECH PROJECT, 2022
** my_rpg_2017
** File description:
** display menu
*/
#include "my.h"

void manage_menus(sfVector2f cursor, elem *elem)
{
	sfVector2f pos = {658, 235};

	if (cursor.y == 410) {
		elem->inv.active = sfTrue;
		elem->stats.active = sfFalse;
		elem->quest.active = sfFalse;
		fill_inventory(&elem->inv);
		sfSprite_setPosition(elem->inv.cur_spr, pos);
	}
	if (cursor.y == 455) {
		elem->stats.active = sfTrue;
		elem->quest.active = sfFalse;
	}
	if (cursor.y == 500) {
		elem->quest.active = sfTrue;
		elem->stats.active = sfFalse;
	}
}

int check_position_cursor(int *n, sfVector2f cursor, elem *elem)
{
	if (cursor.y == 365)
		*n = 1;
	manage_menus(cursor, elem);
	if (cursor.y == 590) {
		elem->game = sfFalse;
		*n = 1;
	}
	return (0);
}

void manage_menu_cursor_events(sfEvent event, int *n, elem *elem)
{
	sfVector2f change_cursor = sfSprite_getPosition(elem->menu.sprite[1]);

	if ((event.key.code == sfKeyS || event.key.code == sfKeyDown) &&
	change_cursor.y <= 547) {
		change_cursor.y += 45;
		sfSprite_setPosition(elem->menu.sprite[1],
				change_cursor);
	}
	if ((event.key.code == sfKeyZ || event.key.code == sfKeyUp) &&
	change_cursor.y >= 400) {
		change_cursor.y -= 45;
		sfSprite_setPosition(elem->menu.sprite[1],
				change_cursor);
	}
	if (event.key.code == sfKeyReturn)
		check_position_cursor(n, change_cursor, elem);
}

int my_menu_event(sfEvent event, int *n, elem *elem)
{
	(event.type == sfEvtClosed) ? (elem->game = sfFalse,
				sfRenderWindow_close(elem->window)) : 0;
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape) {
		if (elem->inv.active == sfTrue ||
		elem->stats.active == sfTrue || elem->quest.active == sfTrue) {
			elem->inv.active = sfFalse;
			elem->stats.active = sfFalse;
			elem->quest.active = sfFalse;
		} else
			*n = 1;
		return (0);
	}
	if (elem->inv.active == sfTrue && event.type == sfEvtKeyPressed) {
		cursor_movements(&elem->inv, event);
		(event.key.code == sfKeyReturn) ? (manage_user_item
		(sfSprite_getPosition(elem->inv.cur_spr), &elem->inv)) : 0;
	}
	if (event.type == sfEvtKeyPressed && elem->inv.active == sfFalse)
		manage_menu_cursor_events(event, n, elem);
	return (0);
}

void display_menu(elem *elem)
{
	int n = 0;
	sfEvent event;

	while (n != 1 && sfRenderWindow_isOpen(elem->window)) {
		while (sfRenderWindow_pollEvent(elem->window, &event))
			my_menu_event(event, &n, elem);
		display(*elem);
		sfRenderWindow_drawSprite(elem->window, elem->menu.sprite[0],
					NULL);
		sfRenderWindow_drawSprite(elem->window, elem->menu.sprite[1],
					NULL);
		sfRenderWindow_display(elem->window);
	}
}
