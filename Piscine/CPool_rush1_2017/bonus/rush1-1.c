/*
** EPITECH PROJECT, 2017
** Rush 01
** File description:
** Displays a square
*/

#include	<unistd.h>

int my_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void my_condition2(int ligne, int colonne, int x, int y)
{
	if (ligne == 1 || ligne == y || colonne >= 1 || colonne <= x)
		my_putchar('-');
	else if (colonne == 1 && (ligne > 1 && ligne < x))
		my_putchar('|');
	else
		my_putchar(' ');
}

void my_condition1(int ligne, int colonne, int x, int y)
{
	if ((ligne == 1 && colonne == 1) || (ligne == 1 && colonne == x))
		my_putchar('o');
	else if ((ligne == y && colonne == 1) || (ligne == y && colonne == x))
		my_putchar('o');
	else
		my_condition2(ligne, colonne, x, y);
}

void rush(int x, int y)
{
	if (x < 1 || y < 1)
		write (2, "Invalid size\n", 13);
	for (int ligne = 1; ligne <= y; ligne++) {
		for (int colonne = 1; colonne <= x; colonne++)
			my_condition1(ligne, colonne, x, y);
		my_putchar('\n');
	}
}

int main(void)
{
	rush(5,5);
}
