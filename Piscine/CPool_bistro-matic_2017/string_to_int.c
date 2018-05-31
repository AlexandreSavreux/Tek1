/*
** EPITECH PROJECT, 2017
** string to int
** File description:
** convert string to int
*/

int string_to_int(char *str)
{
	int i = 0;
	int negatif = 1;
	int result = 0;

	while (str[i] != '\0') {
		if (str[i] == '-') {
			i++;
			negatif = -1;
		}
		result = result * 10 + char_to_int(str[i]);
		i++;
	}
	return (result * negatif);
}
