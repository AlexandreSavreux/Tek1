/*
** EPITECH PROJECT, 2017
** my_strncpy
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char *src, int n)
{
	while (n != 0) {
		dest[n] = src[n];
		n--;
	}
	return (dest);
}
