/*
** EPITECH PROJECT, 2017
** my_revstr.c
** File description:
** Reverses a string
*/
int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i++;
	}
	return (i);
}

char *my_revstr(char *str)
{
	int j = my_strlen(str) - 1;
	char temp;

	for(int i = 0; i < j; i++ ) {
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		j--;
	}
	return (str);
}
