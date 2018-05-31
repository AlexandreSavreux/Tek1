/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include <stdlib.h>
#include "my.h"

static int find_len(int nb)
{
	int len = 0;
	int tmp = nb;

	while (tmp > 0) {
		tmp /= 10;
		len++;
	}
	if (nb == 0)
		len++;
	return (len);
}

char *itos(int nb)
{
	int len = find_len(nb);
	char *str;

	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (nb == 0) {
		str[0] = '0';
		return (str);
	}
	while (len--) {
		str[len] = nb % 10 + '0';
		nb /= 10;
	}
	return (str);
}