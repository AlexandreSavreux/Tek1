/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** Assemble deux strings
*/

char *my_strcat(char *dest, char const *src)
{
	int i;
	unsigned int size = my_strlen(dest)

	for (i = 0; src[i] != '\0'; i++) {
		dest[size + i] = src[i];
	}
	dest[size + i] = '\0';
	return (dest);
}
