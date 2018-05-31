/*
** EPITECH PROJECT, 2018
** menu.c
** File description:
** do the menu for my_rpg
*/

#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include "my.h"
#include "menu.h"

void destroy_main_menu(sfRenderWindow *window, first_menu_t *main_menu,
	elem elem)
{
	int n = 0;

	while (n != 15) {
		sfTexture_destroy(main_menu->texture[n]);
		sfSprite_destroy(main_menu->sprite[n]);
		n++;
	}
	sfMusic_stop(main_menu->music[0]);
	sfMusic_destroy(main_menu->music[0]);
	destroy(elem);
	sfRenderWindow_destroy(window);
}

int load_menu_assets(first_menu_t *main_menu)
{
	for (int n = 0; n < 15; n++) {
		main_menu->texture[n] = sfTexture_createFromFile
			(MENU_TEXTURES[n], NULL);
		if (!main_menu->texture[n])
			return (84);
		main_menu->sprite[n] = sfSprite_create();
		sfSprite_setTexture(main_menu->sprite[n], main_menu->texture[n],
			sfTrue);
	}
	return (resize_asset_first_menu(main_menu));
}

void display_main_menu(sfRenderWindow *window, first_menu_t main_menu)
{
	sfRenderWindow_clear(window, sfBlack);
	sfRenderWindow_drawSprite(window, main_menu.sprite[0], NULL);
	sfRenderWindow_drawSprite(window, main_menu.sprite[1], NULL);
	sfRenderWindow_drawSprite(window, main_menu.sprite[2], NULL);
	sfRenderWindow_drawSprite(window, main_menu.sprite[3], NULL);
	sfRenderWindow_drawSprite(window, main_menu.sprite[12], NULL);
	sfRenderWindow_display(window);
}

void check_event_first_menu(sfEvent event, sfRenderWindow *window,
	first_menu_t *main_menu, elem elem)
{
	if (event.type == sfEvtClosed)
		sfRenderWindow_close(window);
	else if (event.type == sfEvtMouseButtonPressed)
		check_mouse_click(main_menu, window, event, elem);
	if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
		sfRenderWindow_close(window);
}

int do_start(void)
{
	elem elem;
	sfEvent event;
	first_menu_t main_menu;

	if (!create_elem(&elem) || load_menu_assets(&main_menu) == 84 ||
	display_logo(elem.window) == 84)
		return (84);
	sfMusic_play(main_menu.music[0]);
	while (sfRenderWindow_isOpen(elem.window)) {
		while (sfRenderWindow_pollEvent(elem.window, &event))
			check_event_first_menu(event, elem.window, &main_menu,
				elem);
		check_cursor_click(&main_menu, elem.window);
		display_main_menu(elem.window, main_menu);
	}
	destroy_main_menu(elem.window, &main_menu, elem);
	return (0);
}
