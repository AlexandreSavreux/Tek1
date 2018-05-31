/*
** EPITECH PROJECT, 2017
** my_put_nbr
** File description:
** my_put_nbr
*/

#include <stdio.h>

int my_getnbr(char const *str)
{
	int i = 0;
	int tmp = 0;
	int nb = 0;

	while (str[i] < '0' || str[i] > '9') {
		if (str[i] == '-')
			tmp++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10;
		nb = nb + str[i] - '0';
		i++;
	}
	if (tmp % 2 == 1) {
		nb = nb * -1;
	}
	return (nb);
}
