/*
** EPITECH PROJECT, 2022
** CPE_matchstick_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static int my_parse(int i, char c, char *str)
{
	for (; str[i] == c; i++);
	return (i);
}

static int count_word(char *str, char c)
{
	int i = 0;
	int n = 1;
	while (str[i] != '\0' && str[i] != '\n') {
		if (str[i] == c && str[i + 1] != '\0')
			n++;
		i++;
	}
	return (n);
}

static int countchar(char *str, char c)
{
	int cpt = 0;
	while ((str[cpt] != c) && (str[cpt] != '\0') && (str[cpt] != '\n'))
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

	str = my_clean_str(str);
	str = my_strcat(str, "\0");
	tab = malloc(sizeof(*tab) * ((count_word(str, c) + 1)));
	while (str[i] != '\0' && str[i] != '\n') {
		if (str[i] == c) {
			i = my_parse(i, c, str);
			b = 0;
		}
		tab[a] = malloc(
			sizeof(**tab) * (((countchar(str, c) + i) + 10)));
		while ((str[i] != c) && (str[i] != '\0') && (str[i] != '\n'))
			tab[a][b++] = str[i++];
		tab[a++][b] = '\0';
	}
	tab[a] = 0;
	return (tab);
}