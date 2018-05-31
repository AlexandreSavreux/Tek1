/*
** EPITECH PROJECT, 2017
** my_strncmp.c
** File description:
** Compares the lenght of n first characters of two strings
*/

int my_strncmp(char const *s1 , char const *s2, int n)
{
	int i = 0;

	n--;
	while (i < n && s1[i] == s2[i]) {
		i++;
	}
	return (s1[i] - s2[i]);
}
