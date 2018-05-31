/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "my.h"

int my_put_nbr(int nb)
{
	int mod = 0;

	if (nb < 0) {
		write(1, "-", 1);
		nb = -nb;
	}
	if (nb >= 10) {
		mod = nb % 10;
		nb = (nb - mod) / 10;
		my_put_nbr(nb);
		my_putchar(mod + '0');
	} else {
		my_putchar(nb % 10 + '0');
	}
}