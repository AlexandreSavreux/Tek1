/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static int my_parse(int i, char c, char *str)
{
	while (str[i] == c)
		i++;
	return (i);
}

static int count_word(char *str, char c)
{
	int i = 0;
	int n = 1;
	while (str[i] != '\0') {
		if (str[i] == c)
			n++;
		i++;
	}
	return (n);
}

static int countchar(char *str, char c)
{
	int cpt = 0;
	while ((str[cpt] != c) && (str[cpt] != '\0'))
		cpt++;
	cpt++;
	return (cpt);
}

char **my_str_to_wordarray(char *str, char c)
{
	char **tab;
	int i = 0;
	int b = 0;
	int a = 0;

	tab = malloc(sizeof(*tab) * ((count_word(str, c) + 1)));
	while (str[i] != '\0') {
		if (str[i] == c) {
			i = my_parse(i, c, str);
			a++;
			b = 0;
		}
		tab[a] = malloc(
			sizeof(**tab) * (((countchar(str, c) + i) + 1)));
		while ((str[i] != c) && (str[i] != '\0'))
			tab[a][b++] = str[i++];
		tab[a][b] = '\0';
	}
	tab[a + 1] = 0;
	return (tab);
}
