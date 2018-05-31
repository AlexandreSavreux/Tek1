/*
** EPITECH PROJECT, 2017
** infin div
** File description:
** make infinite division
*/
#include "include/my.h"
#include <stdlib.h>

char *infin_div(char *str1, char *str2)
{
	int nb1 = 0;
	int nb2 = my_getnbr(str2);
	char *div = malloc(sizeof(char) * my_strlen(str1) + 1);
	char *resultat = malloc(sizeof(char) * my_strlen(str1) + 2);
	int i = 0;

	while (i != 2 && str1[i] != '\0') {
		nb1 = nb1 * 10 + char_to_int(str1[i]);
		i++;
	}
	free(div);
	resultat[0] = int_to_char(nb1 / nb2);
	while (nb1 / nb2 * nb2 != my_getnbr(str1)) {
		my_putchar('a');
	}
	return (resultat);
}

int main(int ac, char **av)
{
	my_putstr(infin_div(av[1], av[2]));
	my_putchar('\n');
}