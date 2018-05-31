/*
** EPITECH PROJECT, 2017
** simple_window.c
** File description:
** Displays a window
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <stdlib.h>
#include "my.h"

sfSprite* my_drawer(sfTexture* texture, sfSprite* sprite, sfRenderWindow *window)
{
	texture = sfTexture_create(800, 600);
	if (!texture)
		return EXIT_FAILURE;
	sprite = sfSprite_create();
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (sprite);
}

void manage_mouse_click(sfMouseButtonEvent event)
{
	//my_putstr("x = ");
	//	my_put_nbr(event.x);
	//	my_putchar('\n');
	//	my_putstr("y = ");
	//	my_put_nbr(event.y);
	//	my_putchar('\n');
	//	my_putchar('\n');
}

int analyse_events(sfEvent *event, sfRenderWindow *window)
{
	sfMouseButtonEvent mouse;
	sfVector2i position;

	if (event->type == sfEvtClosed)
		sfRenderWindow_close(window);
	if (event->type == sfEvtMouseButtonReleased)
	{
		position = sfMouse_getPosition(window);
		sfMouseButtonEvent mouse = {sfEvtMouseButtonReleased,
					    sfEvtMouseLeft,
					    position.x,
					    position.y};
		manage_mouse_click(mouse);
	}
}

sfIntRect create_IntR(int top, int left, int width, int height)
{
	sfIntRect rect;
	rect.top = top;
	rect.left = left;
	rect.width = width;
	rect.height = height;
	return (rect);
}

int main(void)
{
	sfVideoMode mode = {1280, 720, 32};
	sfRenderWindow *window;
	sfTexture *texture = sfTexture_createFromFile("spritesheet.png", NULL);
	sfSprite *sprite = sfSprite_create();
	sfEvent event;
	char *title = "Je suis un lama";
	int currentSprite = 2;
	sfIntRect duckk = create_IntR(0, 110, 110, 110);

	window = sfRenderWindow_create(mode, title, sfResize | sfClose, NULL);
	if (!window)
		return EXIT_FAILURE;
	sfSprite_setTexture(sprite, texture, sfTrue);
	sfSprite_setTextureRect(sprite, duckk);
	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
			analyse_events(&event, window);
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_display(window);
	}
	sfRenderWindow_destroy(window);
	return EXIT_SUCCESS;
}
