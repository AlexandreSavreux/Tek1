/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void charge_game_assets2(game_t *game)
{
	game->texture[0] = sfTexture_createFromFile(
		"Assets/Sprites/Inventaire.png", NULL);
	game->sprite[0] = sfSprite_create();
	sfSprite_setTexture(game->sprite[0], game->texture[0], sfTrue);
	game->texture[11] = sfTexture_createFromFile(
		"Assets/Sprites/Temps/spritesheet.png", NULL);
	game->sprite[11] = sfSprite_create();
	sfSprite_setTexture(game->sprite[11], game->texture[11], sfTrue);
	game->texture[13] = sfTexture_createFromFile(
		"Assets/Sprites/GAME OVER.png", NULL);
	game->sprite[13] = sfSprite_create();
	sfSprite_setTexture(game->sprite[13], game->texture[13], sfTrue);
	game->texture[14] = sfTexture_createFromFile("Assets/Sprites/LED.png",
		NULL);
	game->sprite[14] = sfSprite_create();
	sfSprite_setTexture(game->sprite[14], game->texture[14], sfTrue);
}

char **char_array(void)
{
	char **string = malloc(sizeof(char *) * 10);

	string[0] = "Assets/Sprites/menu.jpg";
	string[1] = "Assets/Sprites/Play.png";
	string[2] = "Assets/Sprites/Settings.png";
	string[3] = "Assets/Sprites/Quit.png";
	string[4] = "Assets/Sprites/Volume 4.png";
	string[5] = "Assets/Sprites/back.png";
	string[6] = "Assets/Sprites/Volume_plus.png";
	string[7] = "Assets/Sprites/Volume_minus.png";
	string[8] = "Assets/Sprites/Resume.png";
	return (string);
}

void do_mallocString(menu_t *menu)
{
	int i = 0;

	menu->string = malloc(sizeof(char) * 10);
	while (i != 10) {
		menu->string[i] = malloc(sizeof(char) * 30);
		i++;
	}
}

void declare_string(menu_t *menu)
{
	do_mallocString(menu);
	menu->string[0] = "Assets/Sprites/Volume 0.png";
	menu->string[1] = "Assets/Sprites/Volume 1.png";
	menu->string[2] = "Assets/Sprites/Volume 2.png";
	menu->string[3] = "Assets/Sprites/Volume 3.png";
	menu->string[4] = "Assets/Sprites/Volume 4.png";
	menu->string[5] = "Assets/Sprites/Volume 5.png";
	menu->string[6] = "Assets/Sprites/Volume 6.png";
	menu->string[7] = "Assets/Sprites/Volume 7.png";
	menu->string[8] = "Assets/Sprites/Volume 8.png";
	menu->n = 4;
}

int my_helper(void)
{
	my_putstr("USAGE:\n");
	my_putstr("	./my_cook\n");
	my_putstr("DESCRIPTION\n");
	my_putstr("	You have to cook for clients using ");
	my_putstr("displayed keys to put element on screen.\n");
	my_putstr("    You have to be good and quick or you will lose.");
	my_putstr("\nTo play, you have to press 'play' and use your keybord "
		"to make the burger that the game ask on the op left.\n");
	my_putstr("If you do a good burger you mark 200 poins, "
		"if it's not a good burger you will lose 500 points.\n");
	my_putstr("If the score on the top right is equal "
		"or less than 0 you will lose.\n");
	my_putstr("Have a good game\n");
	my_putstr("#TeamMBGE\n");
	return (42);
}