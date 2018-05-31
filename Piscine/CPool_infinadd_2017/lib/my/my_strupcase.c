/*
** EPITECH PROJECT, 2017
** my_strupcase.c
** File description:
** Transforms upper in lowercase
*/

char *my_strupcase(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (96 < str[1] && str[i] < 123)
			str[i] = str[i] - 32;
	}
	return (str);
}
