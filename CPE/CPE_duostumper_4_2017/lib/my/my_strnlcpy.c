/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** copy string after n char
*/

#include <stdlib.h>
#include "my.h"

char *my_strnlcpy(char *str, int n)
{
	char *new_str;
	int i = 0;

	if (n > my_strlen(str))
		return (NULL);
	new_str = malloc(sizeof(char) * (my_strlen(str) - n + 1));
	if (new_str == NULL)
		return (NULL);
	new_str[my_strlen(str) - n] = '\0';
	while (str[n] != '\0') {
		new_str[i] = str[n];
		n++;
		i++;
	}
	return (new_str);
}