/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** returns a number, sent to the function as a string
*/

#include <stddef.h>

int my_get_nbr(char const *str, int *error)
{
	int result = 0;
	int i = 0;

	if (str == NULL)
		return (0);
	if (str[0] == '-')
		i = 1;
	while (str[i] != 0) {
		if (str[i] < '0' || str[i] > '9') {
			(*error) = 1;
			return (-84);
		}
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (str[0] == '-')
		return (result * -1);
	return (result);
}
