/*
** EPITECH PROJECT, 2017
** my_second_rush.c
** File description:
** detect the language
*/

#include "my.h"
#include <unistd.h>

int my_calc(int cpt, int cmp)
{
	int res = 10000 *cmp / cpt;
	return (res);
}

int alpha_len(char *s1)
{
	int j = 0;
	int cpt = 0;

	while (s1[j] != '\0') {
		if ((s1[j] >= 65 && s1[j] <= 90)
		    || (s1[j] >= 97 && s1[j] < 123))
			cpt++;
		j++;
	}
	return (cpt);
}
char my_struppercase(char *s2)
{
	if (s2[0] >= 65 && s2[0] <= 90)
		s2[0] = s2[0] + 32;
	else if (s2[0] >= 97 && s2[0] <= 122)
		s2[0] = s2[0] - 32;
	return (s2[0]);
}
int counter(char *s1, char *s2)
{
	int i = 0;
	int cmp = 0;

	while (s1[i] != '\0') {
		if (s1[i] == *s2 || s1[i] == my_struppercase(s2)) {
			cmp++;
		}
		i++;
	}
	return (cmp);
}

