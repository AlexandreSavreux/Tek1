/*
** EPITECH PROJECT, 2022
** PROJET
** File description:
** Created by romain,
*/

#include <stdlib.h>
#include "my.h"

int int_len(int nbr)
{
	int i = 0;

	for (; nbr > 0; i++) {
		nbr /= 10;
	}
	return (i);
}

void int_sfText(sfText *text, int nbr)
{
	int pos = int_len(nbr) - 1;
	int size = int_len(nbr);
	char str[size + 1];

	while (pos >= 0) {
		str[pos] = nbr % 10 + 48;
		nbr /= 10;
		pos--;
	}
	str[size] = '\0';
	sfText_setString(text, str);
}

void fill_text(inventory *inv, int y, int x, int i)
{
	sfVector2f pos = {625, 335};

	pos.x = pos.x + x * 119;
	pos.y = pos.y + y * 120;
	int_sfText(inv->item[i].text, inv->item[i].nbr);
	sfText_setFont(inv->item[i].text, inv->item[i].font);
	sfText_setCharacterSize(inv->item[i].text, 15);
	sfText_setPosition(inv->item[i].text, pos);
}

void fill_inventory(inventory *inv)
{
	int i = 0;
	int y = 0;
	int x = 0;
	sfVector2f pos = {630, 265};
	sfVector2f stock = pos;

	for (; i < NB_ITEMS && inv->active == sfTrue; i++) {
		(x == NB_ITEMS) ? (x = 0 && y++) : 0;
		if (inv->item[i].nbr > 0) {
			pos.y = pos.y + y * 120;
			pos.x = pos.x + x * 119;
			sfSprite_setPosition(inv->item[i].spr,
					pos);
			fill_text(inv, y, x, i);
			pos = stock;
			x++;
		}
	}
}
