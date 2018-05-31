/*
** EPITECH PROJECT, 2018
** include
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#define NB_ITEMS 4
#define NB_WEAPON 4
#define NB_ROOMS 5
#define NB_PNJ 2

typedef enum map {
	SPAWN,
	KITCHEN,
	WAREHOUSE,
	CAFET,
	HALL,
} map;

enum item {
	KNIFE,
	ROCKET,
	AK47,
	GRENADE,
	EXPLOSION,
};

enum pnj {
	TERRORIST,
	TALIBAN,
};

enum weapon {
	WEAPON,
	BULLET,
};

enum stat {
	CHICKEN,
	MENU,
	XP,
};

#include "structures.h"

typedef struct elem {
	sfRenderWindow *window;
	sfSprite *chicken;
	sfTexture *chicken_tex;
	sfClock *chicken_clock;
	room map[NB_ROOMS];
	map room;
	inventory inv;
	quest_manager_t quest;
	menu menu;
	stats stats;
	pnjs pnj[2];
	sfBool game;
	pickup_items items;
	pnj_chicken pnj_chicken;
	damage damage;
} elem;

//create functions

int create_elem(elem *elem);
int create_inventory_window(inventory *inv);
int create_maps(elem *elem);
int create_user_iud(user *user);
int create_ak47(user *user);
int create_pnj(pnjs *pnj);
int create_stats(stats *stats);
int create_quests(quest_manager_t *quest);
int create_taliban_pnj(pnjs *pnj);
int create_items(pickup_items *items);

//display functions

void display(elem elem);
void display_menu(elem *elem);
void display(elem elem);
void display_inventory(sfRenderWindow *window, inventory inv);
void display_user_iud(user user, sfRenderWindow *window);
void display_rockets(sfRenderWindow *window, elem elem);
void display_ak47(sfRenderWindow *window, elem elem);
void display_pnj(sfRenderWindow *window, pnjs *pnj);
void display_cut(sfRenderWindow *window, user user);
void display_stats(sfRenderWindow *window, stats stats);
void display_chicken_text(elem *elem);
void display_quest(sfRenderWindow *window, quest_manager_t quest);
void display_taliban_pnj(sfRenderWindow *window, pnjs *pnj);
void display_pickup_items(sfRenderWindow *window, pickup_items items, map room,
	inventory inv);

//events functions

void manage_events(sfEvent event, elem *elem);
void manage_user_item(sfVector2f pos, inventory *inv);
void manage_cut(user *user);
void manage_rocket_move(elem *elem);
void manage_cut(user *user);
void pickup_events(elem *elem, sfEvent event);
void ak47(sfSprite *chicken, user *user);
void manage_ak47(user *user);
void manage_pnj(map room, pnjs *pnj, sfSprite *chicken);
void do_warehouse_move(pnjs *pnj, sfSprite *chicken);
void manage_hp_rect_warehouse(pnjs *pnj);
void manage_attack_pnj_warehouse(pnjs *pnj);
void ak47_pnj_warehouse(sfSprite *pnj_spr, pnjs *pnj);
void manage_spawn(pnjs *pnj, map room);
void do_kitchen_move(pnjs *pnj, sfSprite *chicken);
void manage_hp_rect(pnjs *pnj);
void manage_attack_pnj(pnjs *pnj);
void ak47_pnj(sfSprite *pnj_spr, pnjs *pnj);
void do_cafet_move(pnjs *pnj, sfSprite *chicken);
void manage_attack_pnj_cafet(pnjs *pnj);
void manage_hp_rect_cafet(pnjs *pnj);
void ak47_pnj_cafet(sfSprite *pnj_spr, pnjs *pnj);
void do_hall_move(pnjs *pnj, sfSprite *chicken);
void manage_hp_rect_hall(pnjs *pnj);
void manage_attack_pnj_hall(pnjs *pnj);
void ak47_pnj_hall(sfSprite *pnj_spr, pnjs *pnj);
void manage_pnj(map room, pnjs *pnj, sfSprite *chicken);
void manage_taliban_pnj(map room, elem *elem, sfSprite *chicken);
void rocket_pnj(sfSprite *pnj_spr, elem *elem);
void manage_taliban_attack_pnj(pnjs *pnj);
void manage_taliban_hp_rect(pnjs *pnj);
void manage_taliban_spawn(pnjs *pnj, map room);
void do_taliban_kitchen_move(elem *elem, sfSprite *chicken);
void do_taliban_explosion(pnjs *pnj);
int manage_hitbox_taliban_rocket(elem *elem);
void change_hitbox_taliban_rocket(float rotation, sfIntRect *rect);
void manage_taliban_attack_warehouse_pnj(pnjs *pnj);
void do_taliban_warehouse_move(elem *elem, sfSprite *chicken);
void manage_taliban_hp_rect_warehouse(pnjs *pnj);
void manage_taliban_hp_rect_cafet(pnjs *pnj);
void manage_taliban_hp_rect_cafet(pnjs *pnj);
void do_taliban_cafet_move(elem *elem, sfSprite *chicken);
void manage_taliban_hp_rect_hall(pnjs *pnj);
void manage_taliban_attack_hall_pnj(pnjs *pnj);
void do_taliban_hall_move(elem *elem, sfSprite *chicken);
void cut(sfSprite *chicken, user *user);
void rocket_shoot(sfSprite *chicken, user *user);
void manage_rocket_move(elem *elem);
void do_explosion(user *user);
void damage_managing_taliban(elem *elem);
int check_time_knife(damage *damage);
int check_time_rocket(damage *damage);
int check_time_ak47(damage *damage);
void damage_managing_terrorist(elem *elem);
int check_pnj_hitbox(elem *elem);
void chicken_life(elem *elem);

//menu functions

void cursor_movements(inventory *inv, sfEvent event);
void fill_inventory(inventory *inv);
void select_my_chicken(first_menu_t *main_menu, sfRenderWindow *window,
		elem elem);
int display_logo(sfRenderWindow *window);
int settings_main_menu(first_menu_t *main_menu, sfRenderWindow *window);
int resize_asset_first_menu(first_menu_t *main_menu);
void check_cursor_click(first_menu_t *main_menu, sfRenderWindow *window);
void check_mouse_click(first_menu_t *main_menu, sfRenderWindow *window,
		sfEvent event, elem elem);
void destroy_main_menu(sfRenderWindow *window, first_menu_t *main_menu,
		elem elem);
void change_button(first_menu_t *main_menu, sfRenderWindow *window);
void display_my_chicken(first_menu_t *main_menu, sfRenderWindow *window);
void prepare_screen(clock_d *hour, first_menu_t *main_menu);
void prepare_image_second(loading_screen_t *load, sfColor *color);
void color_button_play_select(first_menu_t *main_menu, elem elem);

//other functions

void move_chicken(elem *elem);
void destroy(elem elem);
int rpg(elem elem);
void check_map_change(elem *elem);
void change_room(elem *elem, sfVector2f pos, map room);
void int_sfText(sfText *text, int nbr);
int do_start(void);
void init_values(elem *elem);
int check_if_completed(quest_manager_t *quests);
void check_quests(elem *elem);
void check_stats(elem *elem);

#endif
