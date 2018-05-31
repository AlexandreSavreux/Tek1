/*
** EPITECH PROJECT, 2018
** my_del_tild
** File description:
** my_del_tild
*/
#include "my.h"

static char *clean_str_begin_end(char *str)
{
	unsigned int i = 0;

	while (str[0] == ' ' && str[1]) {
		i = 0;
		while (str[i]) {
			str[i] = str[i + 1];
			i++;
		}
	}
	i = 0;
	while (str[i])
		i++;
	if (i > 0 && str[i - 1] == ' ')
		str[i - 1] = 0;
	return (str);
}

char *my_clean_str(char *str)
{
	unsigned int i = 0;
	unsigned int j = 0;

	while (str[i] != '\0') {
		j = i;
		if (str[i] == '\t')
			str[i] = ' ';
		if (str[i] && str[i] == ' ' && str[i + 1] == ' ') {
			while (str[j]) {
				str[j] = str[j + 1];
				j++;
			}
			i--;
		}
		i++;
	}
	str = clean_str_begin_end(str);
	return (str);
}
