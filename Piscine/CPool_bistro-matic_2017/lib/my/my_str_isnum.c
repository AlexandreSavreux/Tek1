/*
** EPITECH PROJECT, 2017
** my_str_isnum
** File description:
** find if the str is num
*/

int	my_str_isnum(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		if (i== 0 && (str[0] == 45 || str[0] == 43))
			i++;
		if (str[i] > 47 && str[i] < 58)
			i++;
		else
			return(0);
	}
	return(1);
}
