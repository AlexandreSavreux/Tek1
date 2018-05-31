/*
** EPITECH PROJECT, 2017
** simple_window.c
** File description:
** Displays a window
*/

#include <SFML/Graphics.h>


int main()
{
	sfVideoMode mode = {800, 600, 32};
	sfRenderWindow* window;
	sfEvent event;

	window = sfRenderWindow_create(mode, "Je suis une licorne", sfResize | sfClose, NULL);
	if (!window)
		return (1);
	while (sfRenderWindow_isOpen(window))
	{
		while (sfRenderWindow_pollEvent(window, &event))
		{
			if (event.type == sfEvtClosed)
				sfRenderWindow_close(window);
		}
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_display(window);
	}
}
