/*
** EPITECH PROJECT, 2017
** char_to_float
** File description:
** converts a char to a float
*/

#include "../../include/my.h"

float char_to_float(char *str)
{
	int i = 0;
	int len;
	float facteur;
	float res = 0;

	if (str[0] == '-' || str[0] == '+')
		i++;
	for (len = i; str[len] > 47 && str[len] < 58; len++);
	if (str[0] == '-' || str[0] == '+')
		len--;
	facteur = puissance(len - 1);
	for (; str[i] > 47 && str[i] < 58 || str[i] == '.'; i++) {
		if (str[i] == '.')
			i++;
		res = res + (str[i] - 48) * facteur;
		facteur = facteur / 10;
	}
	if (str[0] == '-')
		res = res * (-1);
	return (res);
}
