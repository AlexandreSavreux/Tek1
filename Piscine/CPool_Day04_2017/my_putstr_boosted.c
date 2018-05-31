/*
** EPITECH PROJECT, 2017
** my_putstr_boosted.c
** File description:
** Boosted by Tek3
*/

int my_putstr_boosted(char const *str)
{
	write(1, str, my_strlen(str));
	return (0);
}
