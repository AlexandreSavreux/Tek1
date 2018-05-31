/*
** EPITECH PROJECT, 2017
** my_str_isnum.c
** File description:
** Detects if there is a number
*/

int my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if ((str[i] < '0' || str[i] > '9' ) &&
		    (str[0] != '-' || str[0] != '+'))
			return (1);
		i++;
	}
	return (0);
}
