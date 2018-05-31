/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include <stdlib.h>

int my_strncmp(const char *str1, const char *str2, int nb)
{
	int idx = 0;

	if (str1 == NULL || str2 == NULL)
		return (-1);
	while (str1[idx] && str2[idx] && idx < nb) {
		if (str1[idx] != str2[idx])
			return (str1[idx] - str2[idx]);
		idx++;
	}
	if (idx < nb)
		return (-1);
	return (0);
}