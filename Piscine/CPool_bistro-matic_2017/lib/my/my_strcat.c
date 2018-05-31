/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** Assemble deux strings
*/

char *my_strcat(char *dest, char const *src)
{
	int i;

	for (i = 0; dest[i] != '\0'; i++);
	for (int n = 0; src[n] != '\0'; n++) {
		dest[i] = src[n];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
