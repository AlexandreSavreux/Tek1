/*
** EPITECH PROJECT, 2017
** my_print_revalpha.c
** File description:
**
*/
int	my_print_revalpha (void)
{
	char lettre = 122;

	while (lettre > 96) {
		my_putchar(lettre);
		lettre--;
	}
}
