/*
** EPITECH PROJECT, 2017
** my_print_alpha
** File description:
** display the lowercase alphabet
*/
int	my_print_alpha (void)
{
	char lettre = 97;

	while (lettre < 123) {
		my_putchar(lettre);
		lettre++;
	}
}
