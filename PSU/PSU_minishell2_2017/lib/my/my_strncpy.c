/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

char *my_pimped_strncpy(char *dest, char const *src, int n, int start)
{
	for (int i = 0; src[i] != '\0' && n > i; i++) {
		dest[i] = src[start];
		start++;
	}
	dest[n] = '\0';
	return (dest);
}

char *my_strncpy(char *dest, char const *src, int n)
{
	int i = 0;

	for (; src[i] != '\0' && n > i; i++) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}