/*
** EPITECH PROJECT, 2017
** my_show_word_array.c
** File description:
** Displays the content of an array of words.c
*/

int my_show_word_array (char * const *tab)
{
	for (int i = 0; tab[i] != '\0'; i++) {
		if (tab[i][0] != '\0') {
			my_putstr(tab[i]);
			my_putchar('\n');
		}
	}
	return (0);
}
