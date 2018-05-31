/*
** EPITECH PROJECT, 2017
** myr_float.c
** File description:
** Displays a float number with 2 digits after comma only
*/
#include "my.h"

void my_putchar(char c);
void my_float(int nb)
{
	int rest = nb % 100;
	int entier = (nb - rest) / 100;
	my_put_nbr(entier);
	my_putchar('.');
	if(rest >= 0 && rest <= 9){
		my_putchar('0');
		my_put_nbr(rest);
	}
	else
		my_put_nbr(rest);
}
