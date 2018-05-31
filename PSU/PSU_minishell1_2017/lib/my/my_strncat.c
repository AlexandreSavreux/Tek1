/*
** EPITECH PROJECT, 2017
** my_strcat
** File description:
** my_strcat
*/
#include "my.h"

char *my_strncat(char *dest, char const *str, int nb)
{
	int idx_dest;
	int idx_src;

	idx_dest = my_strlen(dest);
	idx_src = 0;
	while (idx_src < nb && str[idx_src]) {
		dest[idx_dest] = str[idx_src];
		idx_dest += 1;
		idx_src += 1;
	}
	dest[idx_dest] = '\0';
	return (dest);
}
