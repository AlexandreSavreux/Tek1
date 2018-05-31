/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

char *my_strncpy(char *dest, char const *src, int n, int start)
{
	for (int i = 0; src[i] != '\0' && n > i; i++) {
		dest[i] = src[start];
		start++;
	}
	dest[n] = '\0';
	return (dest);
}