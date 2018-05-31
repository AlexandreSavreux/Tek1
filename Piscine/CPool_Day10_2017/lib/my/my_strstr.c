/*
** EPITECH PROJECT, 2017
** my_strstr
** File description:
** Finds a word into a string
*/

char	*my_strstr(char const *str,char const*to_find)
{
	int i = 0;
	int n = 0;
	int o = 0;
	int mot = 0;

	while (to_find[o] != '\0') {
		o++;
	}
	while (str[i] != '\0' && n < o) {
		n = 0;
		while (str[i] == to_find[mot]) {
			n++;
			i++;
			mot++;
		}
		mot = 0;
		i++;
	}
	mot = i-o;
	return (mot);
}
