/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Returns a number sent to the function as a string
*/

int	my_getnbr(char const *str)
{
	int i = 0;
	int nb = 0;

	while (str[i] >= 48 && str[i] <= 57) {
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}
