/*
** EPITECH PROJECT, 2017
** my_evil_str.c
** File description:
** Shake your chars
*/

int my_strlen2(char const *str)
{
	int i = 0;

	while	(str[i] != '\0') {
		i++;
	}
	return (i);
}

char* my_evil_str(char* str)
{
	int nbar2 = 0;
	char lettre;
	int nbar1;

	nbar1 = my_strlen2(str) - 1;
	while(nbar2 < nbar1) {
		lettre = str[nbar2];
		str[nbar2] = str[nbar1];
		str[nbar1] = lettre;
		nbar2++;
		nbar1--;
	}
	return (str);
}
