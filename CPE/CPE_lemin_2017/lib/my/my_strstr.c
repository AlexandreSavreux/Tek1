/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

int my_strstr(char *wanted, char *s2)
{
	int i = 0;

	while (wanted[i]) {
		if (wanted[i] < s2[i])
			return (-1);
		else if (wanted[i] > s2[i])
			return (1);
		else
			i++;
	}
	return (0);
}