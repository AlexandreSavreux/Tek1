#include <SFML/Window/Event.h>
#include "my.h"

int buttonIsFocused(button_t button, sfVector2f clickPosition)
{
	return (clickPosition.x < sfRectangleShape_getPosition(button.rect).x +
		sfRectangleShape_getSize(button.rect).x &&
		clickPosition.x > sfRectangleShape_getPosition(button.rect).x &&
		clickPosition.y < sfRectangleShape_getPosition(button.rect).y +
			sfRectangleShape_getSize(button.rect).y &&
		clickPosition.y > sfRectangleShape_getPosition(button.rect).y);
}

void *my_hello()
{
	my_printf("Hello\n");
}

void manage_mouse_click(button_t button, int x, int y)
{
	sfVector2f pos = {(float)x, (float)y};

	if (buttonIsFocused(button, pos)) {

	}
}

void buttonInitialise(button_t *button, sfVector2f position, sfVector2f size
)
{
	button->rect = sfRectangleShape_create();
	sfRectangleShape_setSize(button->rect, size);
	sfRectangleShape_setPosition(button->rect, position);
	sfRectangleShape_setFillColor(button->rect, sfRed);
}

int main()
{
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow *window;
	sfTexture *texture;
	sfSprite *sprite;
	sfEvent event;
	sfVector2f pos = {20, 20};
	sfVector2f size = {200, 200};
	button_t play;

	window = sfRenderWindow_create(mode, "SFML window", sfResize | sfClose,
		NULL);
	if (!window)
		return EXIT_FAILURE;
	/* Load a sprite to display (including its texture) */
	texture = sfTexture_create(800, 600);
	if (!texture)
		return EXIT_FAILURE;
	sprite = sfSprite_create();
	buttonInitialise(&play, pos, size);
	/* Link the texture to the sprite */
	sfSprite_setTexture(sprite, texture, sfTrue);
	/* Limit the window framerate */
	sfRenderWindow_setFramerateLimit(window, 30);
	/* Start the game loop */
	while (sfRenderWindow_isOpen(window)) {
		/* Process events */
		while (sfRenderWindow_pollEvent(window, &event)) {
			/* Close window : exit */
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
			if (event.type == sfEvtMouseButtonReleased)
				manage_mouse_click(play, event.mouseButton.x,
					event.mouseButton.y);
		}
		/* Clear the screen */
		sfRenderWindow_clear(window, sfBlack);
		/* Draw the sprite */
		sfRenderWindow_drawRectangleShape(window, play.rect, NULL);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		/* Update the window */
		sfRenderWindow_display(window);
	}
	/* Cleanup resources */
	sfSprite_destroy(sprite);
	sfTexture_destroy(texture);
	sfRenderWindow_destroy(window);
	return EXIT_SUCCESS;
}