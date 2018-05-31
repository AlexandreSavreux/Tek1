/*
** EPITECH PROJECT, 2017
** my_str_isalpha
** File description:
** my_str_isalpha
*/

int my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] >= '0' && str[i] <= '9') {
		i++;
	}
	if (str[i] == '\0')
		return (1);
	else
		return (0);
}