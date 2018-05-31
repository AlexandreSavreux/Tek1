/*
** EPITECH PROJECT, 2018
** is_charinstr
** File description:
** my.h
*/

int is_charinstr(char *str, char c)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}
