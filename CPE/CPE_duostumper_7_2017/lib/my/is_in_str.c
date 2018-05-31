/*
** EPITECH PROJECT, 2018
** LIB
** File description:
** is_in_str
*/

int is_in_str(char *str, char c)
{
	int i = 0;

	while (str[i] != '\0') {
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}