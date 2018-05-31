/*
** EPITECH PROJECT, 2022
** my_cook_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void screen_score(score_t *score, char *nombre, sfRenderWindow *window,
	char *burger
)
{
	sfVector2f text_move = {1510, 0};
	sfVector2f move_text_burger = {1700, 200};
	sfVector2f move_text = {1290, 200};

	sfText_setString(score->text[0], nombre);
	sfText_setFont(score->text[0], score->font[0]);
	sfText_setCharacterSize(score->text[0], 120);
	sfText_setColor(score->text[0], sfRed);
	sfText_setPosition(score->text[0], text_move);
	sfRenderWindow_drawText(window, score->text[0], NULL);
	sfText_setString(score->text[1], burger);
	sfText_setFont(score->text[1], score->font[1]);
	sfText_setCharacterSize(score->text[1], 100);
	sfText_setColor(score->text[1], sfBlack);
	sfText_setPosition(score->text[1], move_text_burger);
	sfRenderWindow_drawText(window, score->text[1], NULL);
	sfText_setString(score->text[2], "score:");
	sfText_setFont(score->text[2], score->font[2]);
	sfText_setCharacterSize(score->text[2], 100);
	sfText_setColor(score->text[2], sfBlack);
	sfText_setPosition(score->text[2], move_text);
	sfRenderWindow_drawText(window, score->text[2], NULL);
}

void prepare_my_score(score_t *score)
{
	score->score = 1000;
	score->burger = 0;
	score->font[0] = sfFont_createFromFile("Assets/police/police.ttf");
	score->text[0] = sfText_create();
	score->font[1] = sfFont_createFromFile("Assets/police/police.ttf");
	score->text[1] = sfText_create();
	score->font[2] = sfFont_createFromFile("Assets/police/police.ttf");
	score->text[2] = sfText_create();
}

int do_mult(int n)
{
	int i = 1;
	int m = 1;

	while (i != n) {
		m = m * 10;
		i++;
	}
	return (m);
}

void reboot_string(game_t *game)
{
	int n = 1;

	while (n != 12) {
		game->string[n] = '\0';
		n++;
	}
	game->string[0] = 48;
}

char *do_conv(int a, char **nombre)
{
	int n = 0;
	int temp = a;
	int i = 0;
	int m;

	while (temp != 0) {
		temp = temp / 10;
		n++;
	}
	m = do_mult(n);
	temp = a;
	while (i != n) {
		(*nombre)[i] = 48 + (temp / m);
		temp = a - temp % m;
		temp = a - temp;
		m = m / 10;
		i++;
	}
	(*nombre)[n] = '\0';
	return (*nombre);
}