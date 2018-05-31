/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** Returns the number of characters in the string passed as parameter
*/

int my_strlen(char const *str)
{
	int i = 0;

	while	(str[i] != '\0') {
		i++;
	}
	return (i);
}
