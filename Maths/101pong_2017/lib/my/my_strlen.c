/*
** EPITECH PROJECT, 2017
** my_strlen
** File description:
** returns the length of a character string
*/

int my_strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++);
	return (i);
}
