/*
** EPITECH PROJECT, 2018
** destroy
** File description:
** destroys elements
*/

#include <stdlib.h>
#include "my.h"

void destroy_maps_and_stats_and_items(room *map, stats stats,
				pickup_items items)
{
	for (int i = 0; i < NB_ROOMS; i++) {
		sfSprite_destroy(map[i].sprite);
		sfTexture_destroy(map[i].texture);
		free(map[i].block);
	}
	for (int i = 0; i < 3; i++) {
		sfSprite_destroy(stats.sprite[i]);
		sfTexture_destroy(stats.texture[i]);
		sfSprite_destroy(items.sprite[i]);
		sfTexture_destroy(items.texture[i]);
	}
	sfText_destroy(stats.text);
	sfFont_destroy(stats.font);
}

void destroy_quests(quest_manager_t quest)
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			sfText_destroy(quest.quests[i].tasks[j].task);
		sfText_destroy(quest.quests[i].title);
	}
	sfFont_destroy(quest.font);
	sfSprite_destroy(quest.sprite);
	sfTexture_destroy(quest.texture);
}

void destroy_inv(inventory inv)
{
	for (int i = 0; i < 4; i++) {
		sfSprite_destroy(inv.item[i].spr);
		sfTexture_destroy(inv.item[i].tex);
		sfFont_destroy(inv.item[i].font);
		sfText_destroy(inv.item[i].text);
		sfSprite_destroy(inv.user.item[i].spr);
		sfTexture_destroy(inv.user.item[i].tex);
	}
	for (int i = 0; i < 3; i++) {
		sfSprite_destroy(inv.user.item[i].weapon[WEAPON].spr);
		sfTexture_destroy(inv.user.item[i].weapon[WEAPON].tex);
	}
	sfSprite_destroy(inv.user.item[ROCKET].weapon[BULLET].spr);
	sfTexture_destroy(inv.user.item[ROCKET].weapon[BULLET].tex);
	sfClock_destroy(inv.user.item[KNIFE].weapon[WEAPON].clock);
	sfClock_destroy(inv.user.item[ROCKET].weapon[BULLET].clock);
	sfClock_destroy(inv.user.item[AK47].weapon[WEAPON].clock);
}

void destroy_pnj_and_menu(elem elem)
{
	for (int i = 0; i < 2; i++) {
		sfSprite_destroy(elem.menu.sprite[i]);
		sfTexture_destroy(elem.menu.texture[i]);
		sfSprite_destroy(elem.pnj[i].spr);
		sfSprite_destroy(elem.pnj[i].hp_spr);
		sfTexture_destroy(elem.pnj[i].tex);
		sfTexture_destroy(elem.pnj[i].hp_tex);
		sfTexture_destroy(elem.pnj_chicken.texture[i]);
		sfSprite_destroy(elem.pnj_chicken.sprite[i]);
		sfClock_destroy(elem.pnj[i].clock);
		sfSprite_destroy(elem.pnj[i].weapon[WEAPON].spr);
		sfTexture_destroy(elem.pnj[i].weapon[WEAPON].tex);
		sfClock_destroy(elem.pnj[i].weapon[WEAPON].clock);
	}
	sfSprite_destroy(elem.pnj[TALIBAN].weapon[BULLET].spr);
	sfTexture_destroy(elem.pnj[TALIBAN].weapon[BULLET].tex);
	sfClock_destroy(elem.pnj[TALIBAN].weapon[BULLET].clock);
	sfClock_destroy(elem.pnj[TALIBAN].damage.clock_rocket);
	sfClock_destroy(elem.pnj[TALIBAN].damage.clock_ak);
	sfClock_destroy(elem.pnj[TALIBAN].damage.clock_cut);
}

void destroy(elem elem)
{
	sfSprite_destroy(elem.chicken);
	sfTexture_destroy(elem.chicken_tex);
	sfClock_destroy(elem.chicken_clock);
	destroy_maps_and_stats_and_items(elem.map, elem.stats, elem.items);
	destroy_quests(elem.quest);
	destroy_inv(elem.inv);
	destroy_pnj_and_menu(elem);
	sfSprite_destroy(elem.inv.cur_spr);
	sfSprite_destroy(elem.inv.spr);
	sfSprite_destroy(elem.inv.user.spr);
	sfTexture_destroy(elem.inv.tex);
	sfTexture_destroy(elem.inv.cur_tex);
	sfTexture_destroy(elem.inv.user.tex);
	sfClock_destroy(elem.pnj[TERRORIST].damage.clock_rocket);
	sfClock_destroy(elem.pnj[TERRORIST].damage.clock_ak);
	sfClock_destroy(elem.pnj[TERRORIST].damage.clock_cut);
	sfClock_destroy(elem.damage.clock_ak);
	sfClock_destroy(elem.damage.clock_rocket);
}
