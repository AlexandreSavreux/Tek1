/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** Display one by one the characters of a string
*/

int my_putstr(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i++;
	}
	return (0);
}
