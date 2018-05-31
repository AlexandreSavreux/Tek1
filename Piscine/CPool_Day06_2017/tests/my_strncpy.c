/*
** EPITECH PROJECT, 2017
** my_strncpy.c
** File description:
** Copies n characters from a string into another
*/

char *my_strncpy(char *dest, char const *src, int n)
{
	for (int i = 0; src[i] != '\0' && n > 0; i++) {
		dest[i] = src[i];
	}
	dest[n] = '\0';
	return (dest);
}
