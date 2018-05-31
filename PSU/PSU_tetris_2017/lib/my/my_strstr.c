/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_strstr(char *s1, char *s2)
{
	int i = 0;

	while (s1[i]) {
		if (s1[i] < s2[i])
			return (-1);
		else if (s1[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}