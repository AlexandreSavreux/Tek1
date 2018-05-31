/*
** EPITECH PROJECT, 2022
** CPE_getnextline_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

char *suppr_spaces(char *str)
{
	int i = 0;
	int j = 0;
	char *str2 = malloc(my_strlen(str) + 1);

	while (str[i] != '\0') {
		if (str[i] != ' ' || str[i] != '\t') {
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

char *my_strncpy(char *dest, char const *src, int n)
{
	for (int i = 0; src[i] != '\0' && n > i; i++) {
		dest[i] = src[i];
	}
	dest[n] = '\0';
	return (dest);
}

void recup_my_words(char *str)
{
	char *first;
	char *last;
	int i;
	int space;

	for (space = 0; str[space] == ' ' || str[space] == '\t'; space++);
	for (i = space; str[i] != ' ' && str[i] != '\t'; i++);
	first = malloc(sizeof(char) * i + 1);
	first = suppr_spaces(my_strncpy(first, str, i));
	for (space = my_strlen(str);
		str[space] == ' ' || str[space] == '\t'; space--);
	for (i = space; str[i] != ' ' && str[i] != '\t'; i--);
	last = malloc(sizeof(char) * i + 1);
	last = suppr_spaces(my_strncpy(last, str, i));
	my_evil_strarray(first, last);
	free(first);
	free(last);
}

void my_evil_strarray(char *first, char *last)
{
	char *temp;

	my_strncpy(my_strdup(last), last, my_strlen(last));
}

int main(int ac, char **av)
{
	recup_my_words(av[1]);
	my_putchar('\n');
	return (0);
}