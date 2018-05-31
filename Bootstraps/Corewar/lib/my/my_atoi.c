/*
** EPITECH PROJECT, 2017
** my_atoi.c
** File description:
** char* to int
*/

int check_digits(char c)
{
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int my_atoi(char *str)
{
	int res = 0;
	int sign = 1;
	int i = 0;

	if (str[0] == '-') {
		sign = -1;
		i++;
	}
	while (str[i] != '\0') {
		if (check_digits(str[i]) == 0)
			res = res * 10 + (str[i] - 48);
		else
			return (1);
		i++;
	}
	return (sign * res);
}
