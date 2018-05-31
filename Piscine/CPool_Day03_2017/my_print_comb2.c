/*
** EPITECH PROJECT, 2017
** my_print_comb2.c
** File description:
**
*/

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_added_condition(int nb1, int nb2)
{
	if (nb1 != 98 || nb2 != 99) {
		my_putchar(',');
		my_putchar(' ');
	}
}

int display(int x)
{
	char lettre1;
	char lettre2;

	lettre1 = (x / 10) + 48;
	lettre2 = (x % 10) + 48;
	my_putchar(lettre1);
	my_putchar(lettre2);

	return (0);
}

int my_print_comb2(void)
{
	int nb1;
	int nb2;

	nb1 = 0;
	nb2 = 1;
	while (nb1 < 99) {
		nb2 = nb1 + 1;
		while (nb2 < 100) {
			display(nb1);
			my_putchar(' ');
			display(nb2);
			my_added_condition(nb1, nb2);
			nb2 = nb2 + 1;
		}
		nb1 = nb1 + 1;
	}
	return (0);
}

int main(void)
{
	my_print_comb2();
}