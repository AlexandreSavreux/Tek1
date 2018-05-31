/*
** EPITECH PROJECT, 2017
** my_put_nbrbase.c
** File description:
** Convert a int into another base
*/
#include "my.h"

void my_put_nbrbase(long long nb, char const *base)
{
	long long div = 1;
	int size = my_strlen(base);
	int i;

	if (nb < 0) {
		nb = -nb;
		my_putchar('-');
	}
	while ((nb / div) != 0)
		div *= size;
	div /= size;
	while (div != 0) {
		i = 0;
		while ((i < size) && (nb >= div * i))
			i++;
		i--;
		my_putchar(base[i]);
		nb %= div;
		div /= size;
	}
}