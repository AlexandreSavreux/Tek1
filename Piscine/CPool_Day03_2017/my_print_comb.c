/*
** EPITECH PROJECT, 2017
** my_print_comb.c
** File description:
**
*/

void    my_printer (int n1, int n2, int n3)
{
	if (n1 == 55 && n2 == 56 && n3 == 57) {
		my_putchar(n1);
		my_putchar(n2);
		my_putchar(n3);
	} else {
		my_putchar(n1);
		my_putchar(n2);
		my_putchar(n3);
		my_putchar(',');
		my_putchar(' ');
	}
}

void	my_added_loop (int n1, int n2, int n3)
{
	while (n3 <= '9') {
		my_printer(n1, n2, n3);
		n3 = n3 + 1;
	}
}

int     my_print_comb (void)
{
	char	n1;
	char	n2;
	char	n3;

	n1 = '0';
	while (n1 <= '7') {
		n2 = n1 + 1;
		while (n2 <= '8') {
			n3 = n2 + 1;
			my_added_loop(n1,n2,n3);
			n2 = n2 + 1;
		}
		n1 = n1 + 1;
	}
	return (0);
}

