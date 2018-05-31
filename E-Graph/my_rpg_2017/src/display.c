/*
** EPITECH PROJECT, 2018
** display
** File description:
** displays the elements
*/

#include "my.h"

void event_exit_menu(sfEvent event, int *n)
{
	if (event.key.code == sfKeyEscape)
		(*n) = 1;
}

void display_text_event(elem *elem)
{
	int n = 0;
	sfEvent event;

	while (n == 0) {
		while (sfRenderWindow_pollEvent(elem->window, &event))
			event_exit_menu(event, &n);
		display(*elem);
		sfRenderWindow_drawSprite(elem->window,
					elem->pnj_chicken.sprite[1], NULL);
		sfRenderWindow_display(elem->window);
	}
}

void display_chicken_text(elem *elem)
{
	sfVector2f pos_chicken = sfSprite_getPosition(elem->chicken);
	sfVector2f pos_pnj = sfSprite_getPosition(elem->pnj_chicken.sprite[0]);
	sfIntRect rect_chicken = sfSprite_getTextureRect(elem->chicken);

	if (elem->room == SPAWN && (pos_chicken.x >= pos_pnj.x - 50 &&
		pos_chicken.x <= pos_pnj.x + 20)) {
		if ((pos_chicken.y >= pos_pnj.y + 70 &&
		pos_chicken.y <= pos_pnj.y + 110) &&
		rect_chicken.top == 216)
			display_text_event(elem);
	}
}

void display_pnj_chicken(pnj_chicken pnj_chicken, sfRenderWindow *window,
	map room)
{
	if (room == SPAWN)
		sfRenderWindow_drawSprite(window, pnj_chicken.sprite[0], NULL);
}

void display(elem elem)
{
	sfRenderWindow_clear(elem.window, sfBlack);
	sfRenderWindow_drawSprite(elem.window, elem.map[elem.room].sprite,
		NULL);
	display_pickup_items(elem.window, elem.items, elem.room, elem.inv);
	display_pnj_chicken(elem.pnj_chicken, elem.window, elem.room);
	display_rockets(elem.window, elem);
	display_cut(elem.window, elem.inv.user);
	display_ak47(elem.window, elem);
	sfRenderWindow_drawSprite(elem.window, elem.chicken, NULL);
	display_pnj(elem.window, elem.pnj);
	display_taliban_pnj(elem.window, elem.pnj);
	display_user_iud(elem.inv.user, elem.window);
	display_inventory(elem.window, elem.inv);
	display_stats(elem.window, elem.stats);
	display_quest(elem.window, elem.quest);
}
