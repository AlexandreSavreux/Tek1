/*
** EPITECH PROJECT, 2017
** my_strcmp
** File description:
** my_strcmp
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
	int i = 0;

	while (i != n - 1) {
		if (s1[i] < s2[i]) {
			return (-1);
		} else if (s1[i] > s2[i]) {
			return (1);
		}
		i++;
	}
	return (0);
}
