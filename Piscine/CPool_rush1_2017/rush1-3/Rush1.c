/*
** EPITECH PROJECT, 2017
** Rush 01
** File description:
** Displays a square
*/

#include	<unistd.h>

void my_condition2(int ligne, int colonne, int x, int y)
{
if (ligne == 1 || ligne == y || colonne == 1 || colonne == x)
	my_putchar('B');
else
	my_putchar(' ');
}

void my_condition1(int ligne, int colonne, int x, int y)
{
	if ((ligne == 1 && colonne == 1) || (ligne == 1 && colonne == x))
		my_putchar('A');
	else if ((ligne == y && colonne == 1) || (ligne == y && colonne == x))
		my_putchar('C');
	else my_condition2(ligne, colonne, x, y);
}

void my_for_loop(int x, int y)
{
	for (int ligne = 1; ligne <= y; ligne++) {
		for (int colonne = 1; colonne <= x; colonne++)
			my_condition1(ligne, colonne, x, y);
		my_putchar('\n');
	}
}

void rush(int x, int y)
{
	if (x == 1 && y == 1) {
	       	my_putchar('B');
		my_putchar('\n');
	}
	else if (x < 1 || y < 1)
		write (2, "Invalid size\n", 13);
	else my_for_loop(x, y);
}
