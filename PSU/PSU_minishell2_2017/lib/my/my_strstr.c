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

	if (s1 == NULL || s2 == NULL)
		return (50);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}