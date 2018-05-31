/*
** EPITECH PROJECT, 2017
** simple_window.c
** File description:
** Displays a window
*/
#include "struct.h"

void buttonInitialise(button_t *button, sfVector2f position, sfVector2f size
)
{
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(button->rect, size);
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setFillColor(button->rect, sfRed);
}

void move_rect(void)
{
	if (assets_t.boole == 1) {
		sfIntRect rect = {};
		assets_t.boole = 0;
		assets_t.hitbox = rect;
	}
	assets_t.hitbox.top = 0;
	assets_t.hitbox.width = 110;
	assets_t.hitbox.height = 110;
	if (assets_t.hitbox.left < 220) {
		assets_t.hitbox.left += 110;
		sfSprite_setTextureRect(assets_t.sprites[1], assets_t.hitbox);
	} else {
		assets_t.hitbox.left = 0;
		sfSprite_setTextureRect(assets_t.sprites[1], assets_t.hitbox);
	}
}

int run(void)
{
	sfVideoMode mode = {1280, 720, 32};
	sfRenderWindow *window;
	sfEvent event;
	button_t button;

	window = sfRenderWindow_create(mode, "My_hunter", sfClose, NULL);
	if (!window)
		return (1);
	load_textures();
	buttonInitialise(button, {20, 20}, {200, 200});
	sfRenderWindow_setMouseCursorVisible(window, sfFalse);
	sfRenderWindow_setFramerateLimit(window, 240);
	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, &event))
			analyse_events(button, &event, window);
		my_drawer(window);
		my_clock();
	}
	sfRenderWindow_destroy(window);
	return (0);
}
