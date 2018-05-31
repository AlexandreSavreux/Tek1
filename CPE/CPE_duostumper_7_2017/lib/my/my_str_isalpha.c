/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isalpha(char const *str)
{
	int i = 0;

	while (str[i] >= 'a' && str[i] <= 'z' ||
		str[i] >= 'A' && str[i] <= 'Z') {
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}