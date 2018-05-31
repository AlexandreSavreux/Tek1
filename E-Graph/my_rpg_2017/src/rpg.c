/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** rpg game loop
*/

#include "my.h"

void manage_weapons(elem *elem)
{
	if (elem->inv.user.item[ROCKET].weapon[WEAPON].active == sfTrue)
		manage_rocket_move(elem);
	if (elem->inv.user.item[ROCKET].weapon[BULLET].active == sfTrue)
		do_explosion(&elem->inv.user);
	if (elem->inv.user.item[KNIFE].weapon[WEAPON].active == sfTrue)
		manage_cut(&elem->inv.user);
	if (elem->inv.user.item[AK47].weapon[WEAPON].active == sfTrue)
		manage_ak47(&elem->inv.user);
}

void game_loop(elem *elem)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(elem->window, &event))
		manage_events(event, elem);
	move_chicken(elem);
	check_map_change(elem);
	fill_inventory(&elem->inv);
	manage_weapons(elem);
}

int rpg(elem elem)
{
	init_values(&elem);
	while (elem.game == sfTrue) {
		game_loop(&elem);
		manage_pnj(elem.room, elem.pnj, elem.chicken);
		manage_taliban_pnj(elem.room, &elem, elem.chicken);
		damage_managing_taliban(&elem);
		damage_managing_terrorist(&elem);
		chicken_life(&elem);
		check_if_completed(&elem.quest);
		check_quests(&elem);
		check_stats(&elem);
		display(elem);
		sfRenderWindow_display(elem.window);
	}
	sfRenderWindow_setMouseCursorVisible(elem.window, sfTrue);
	return (1);
}
