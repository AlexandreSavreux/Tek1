/*
** EPITECH PROJECT, 2017
** char_to_int
** File description:
** converts a char to an int
*/

#include "../../include/my.h"

int char_to_int(char *str)
{
	int i;
	int res = 0;
	int facteur = 1;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i + 1] == '.')
			str[i + 1] = '\0';
	my_revstr(str);
	for (i = 0; str[i] > 47 && str[i] < 58; i++) {
		res = res + (str[i] - 48) * facteur;
		facteur = facteur * 10;
	}
	if (str[i] == '-')
		res = res * (-1);
	return (res);
}
