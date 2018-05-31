/*
** EPITECH PROJECT, 2018
** structures
** File description:
** header with structures
*/

#ifndef STRUCTURES_H_
#define STRUCTURES_H_

typedef struct bullet
{
	sfSprite *spr;
	sfTexture *tex;
	sfBool active;
	sfClock *clock;
} bullet;

typedef struct damage
{
	sfClock *clock_rocket;
	sfClock *clock_ak;
	sfClock *clock_cut;
} damage;

typedef struct pnjs
{
	sfSprite *spr;
	sfTexture *tex;
	sfSprite *hp_spr;
	sfTexture *hp_tex;
	bullet weapon[NB_PNJ];
	int hp[NB_ROOMS];
	int type;
	damage damage;
	sfClock *clock;
	sfBool active[NB_ROOMS];
} pnjs;

typedef struct items {
	sfTexture *tex;
	sfSprite *spr;
	sfText *text;
	sfFont *font;
	sfClock *clock;
	bullet weapon[NB_WEAPON];
	int nbr;
} items;


typedef struct user_item {
	sfTexture *tex;
	sfSprite *spr;
	int used;
	items item[NB_ITEMS];
} user;

typedef struct inventory {
	sfTexture *tex;
	sfSprite *spr;
	sfTexture *cur_tex;
	sfSprite *cur_spr;
	sfBool active;
	items item[4];
	user user;
} inventory;

typedef struct room {
	sfSprite *sprite;
	sfTexture *texture;
	sfIntRect *block;
	int nb_blocks;
} room;

typedef struct menu {
	sfSprite *sprite[2];
	sfTexture *texture[2];
} menu;

typedef struct stats {
	sfSprite *sprite[3];
	sfTexture *texture[3];
	sfText *text;
	sfFont *font;
	sfBool active;
	int color;
	int life;
	int power;
	int xp;
	int level;
} stats;

typedef struct loading_screen_s {
	sfSprite *sprite[3];
	sfTexture *texture[3];
	sfMusic *music[2];
} loading_screen_t;

typedef struct first_menu_s {
	sfSprite *sprite[15];
	sfTexture *texture[15];
	sfMusic *music[1];
	float volume;
	sfIntRect song;
} first_menu_t;

typedef struct clock_s {
	sfClock *clock;
	sfTime time;
	float second;
} clock_d;

typedef struct task_s {
	sfText *task;
	sfBool done;
} task_t;

typedef struct quest_s {
	sfText *title;
	sfBool completed;
	struct task_s tasks[3];
} quest_t;

typedef struct quest_manager_s {
	struct quest_s quests[2];
	sfFont *font;
	sfSprite *sprite;
	sfTexture *texture;
	sfBool active;
} quest_manager_t;

typedef struct pnj_chicken {
	sfSprite *sprite[2];
	sfTexture *texture[2];
} pnj_chicken;

typedef struct pickup_items {
	sfSprite *sprite[3];
	sfTexture *texture[3];
} pickup_items;

#endif
