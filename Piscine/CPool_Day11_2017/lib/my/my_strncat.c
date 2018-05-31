/*
** EPITECH PROJECT, 2017
** my_strncat.c
** File description:
** Same as previous
*/

char *my_strncat(char *dest, char const *src, int nb)
{
	int i;

	for (i = 0; dest[i] != '\0'; i++) {
	}
	for (int n = 0; src[n] != '\0' && n != nb; n++) {
		dest[i] = src[n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
