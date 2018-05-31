/*
** EPITECH PROJECT, 2017
** my_put_nbrbase.c
** File description:
** Convert a int into another base
*/
#include "my.h"

void my_put_u_nbrbase(long long unsigned nb, char const *base)
{
	unsigned long long div = 1;
	unsigned int size = my_strlen(base);
	unsigned int i;

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
