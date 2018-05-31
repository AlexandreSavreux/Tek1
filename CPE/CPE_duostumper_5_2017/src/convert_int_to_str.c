/*
** EPITECH PROJECT, 2022
** CPE_duostumper_5_2017
** File description:
** Created by Florian Louvet,
*/
#include <stdlib.h>

int int_len(int nbr)
{
	int i = 0;

	for (; nbr > 0; i++) {
		nbr /= 10;
	}
	return (i);
}

char *int_to_str(int nbr)
{
	int pos = int_len(nbr) - 1;
	int size = int_len(nbr);
	char *str = malloc(sizeof(char) * size + 1);

	while (pos >= 0) {
		str[pos] = nbr % 10 + 48;
		nbr /= 10;
		pos--;
	}
	str[size] = '\0';
	return (str);
}