/*
** EPITECH PROJECT, 2018
** events
** File description:
** manages events
*/

#include "my.h"

void manage_weapon_events(elem *elem, sfEvent event)
{
	if (elem->inv.user.used == ROCKET) {
		if (event.key.code == sfKeySpace &&
		elem->inv.user.item[ROCKET].weapon[WEAPON].active == sfFalse)
			rocket_shoot(elem->chicken, &elem->inv.user);
	}
	if (elem->inv.user.used == KNIFE) {
		if (event.key.code == sfKeySpace &&
		elem->inv.user.item[KNIFE].weapon[WEAPON].active == sfFalse)
			cut(elem->chicken, &elem->inv.user);
	}
	if (elem->inv.user.used == AK47) {
		if (event.key.code == sfKeySpace &&
		elem->inv.user.item[AK47].weapon[WEAPON].active == sfFalse)
			ak47(elem->chicken, &elem->inv.user);
	}
}

int manage_inventory_events(elem *elem, sfEvent event)
{
	if (elem->inv.active == sfTrue) {
		cursor_movements(&elem->inv, event);
		if (event.key.code == sfKeyReturn)
			manage_user_item(sfSprite_getPosition
					(elem->inv.cur_spr), &elem->inv);
	}
	if (elem->inv.active == sfTrue || elem->stats.active == sfTrue ||
	elem->quest.active == sfTrue)
		return (0);
	manage_weapon_events(elem, event);
	return (0);
}

void open_menu(elem *elem, int i)
{
	sfVector2f pos = {658, 235};
	sfBool bools[] = {sfFalse, sfFalse, sfFalse};

	bools[i] = sfTrue;
	elem->inv.active = bools[0];
	elem->quest.active = bools[1];
	elem->stats.active = bools[2];
	if (bools[0] == sfTrue)
		sfSprite_setPosition(elem->inv.cur_spr, pos);
}

void open_menus(elem *elem, sfEvent event)
{
	if (event.key.code == sfKeyS) {
		if (elem->stats.active == sfFalse)
			open_menu(elem, 2);
		else
			elem->stats.active = sfFalse;
	}
	if (event.key.code == sfKeyI) {
		if (elem->inv.active == sfFalse)
			open_menu(elem, 0);
		else
			elem->inv.active = sfFalse;
	}
	if (event.key.code == sfKeyQ) {
		if (elem->quest.active == sfFalse)
			open_menu(elem, 1);
		else
			elem->quest.active = sfFalse;
	}
}

void manage_events(sfEvent event, elem *elem)
{
	if (event.type == sfEvtClosed) {
		elem->game = sfFalse;
		sfRenderWindow_close(elem->window);
	}
	if (event.type == sfEvtKeyPressed) {
		if (event.key.code == sfKeyEscape)
			display_menu(elem);
		if (event.key.code == sfKeyReturn)
			display_chicken_text(elem);
		manage_inventory_events(elem, event);
		open_menus(elem, event);
		pickup_events(elem, event);
	}
}
