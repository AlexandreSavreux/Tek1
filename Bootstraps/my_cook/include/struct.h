/*
** EPITECH PROJECT, 2017
** struc.c
** File description:
** Structures for CSFML
*/
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <unistd.h>

struct assets_s {
	sfSprite *sprites[2];
	sfTexture *textures[2];
	sfIntRect hitbox;
	sfMusic *music;
	int boole;
} assets_t;

typedef struct button_s {
	sfRectangleShape *rect;
	void (*callback)();
} button_t;

struct event_s {
	sfVector2i mouse_pos;
	sfVector2f aim_pos;
	sfVector2f duck_speed;
	sfVector2f duck_pos;
	sfVector2f respawn_pos;
} event_t;

int run(void);

void my_clock(void);

void destroyer(void);

void manage_aim(sfRenderWindow *window);

void load_miscs(void);

void load_textures(void);

void my_drawer(sfRenderWindow *window);

void manage_mouse_click(button_t button, int x, int y);

void analyse_events(sfEvent *event, sfRenderWindow *window);

void move_rect(void);