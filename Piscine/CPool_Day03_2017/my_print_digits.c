/*
** EPITECH PROJECT, 2017
** my_print_digits.c
** File description:
** print all digits on a single line
*/
int	my_print_digits (void)
{
	char nb = 48;

	while (nb < 58) {
		my_putchar(nb);
		nb++;
	}
}
