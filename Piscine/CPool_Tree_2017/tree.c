/*
** EPITECH PROJECT, 2017
** tree.c
** File description:
** Displays a magical tree
** depending of the size wanted
*/

#include <unistd.h>

int my_putchar(char c)
{
	write (1, &c, 1);
}

int	my_first(int size) // détermine l'emplacement de la première étoile
{
	int first = 1;
	int i;
	int jump = 4;

	for (i = 1; i < size; i++) {
		if ((i % 2) != 0)
			first = first + jump;
		else if (i !=  1) {
			jump = jump + 2;
			first = first + jump;
		}
	}
	return (first);
}

int my_last(int size)
{
	int i;
	int jump = 6;
	int last = 7;

	for (i = 1; i < size; i++) {
		if ((i % 2) != 0)
			last = last + jump;
		else if (i !=  1) {
			jump = jump + 2;
			last = last + jump;
		}
	}
	return (last);
}

void	my_drawer(int num, int size)
{
	int i;
	int j;
	int jump = 4;
	int nothingh = my_last(size) / 2 - my_first(num) / 2 ;
	int stars = my_first(num) - 1;
	int leaves_height = num + 3;

	for (i = 0; i < leaves_height; i++) {
		for (j = 0; j < nothingh; j++)
			my_putchar(' ');
		for (j = 0; j < stars; j++)
			my_putchar('*');
		nothingh--;
		stars = stars + 2;
		my_putchar('*');
		my_putchar('\n');
	}
}

void my_trunk(int size)
{
	int i;
	int j;
	int nothingh;
	int trunk_width;
	int trunk_height;

	if ((size % 2) != 0)
		trunk_width = size;
	else
		trunk_width = size + 1;
	trunk_height = size;
	nothingh = (my_last(size) / 2) - (trunk_width / 2);
	for (i = 0; i < trunk_height; i++) {
		for (j = 0; j < nothingh; j++)
			my_putchar(' ');
		for (j = 0; j < trunk_width; j++)
			my_putchar('|');
		my_putchar('\n');
	}
}

void tree(int size)
{
	int i;

	if (size > 0)
	{
		i = 1;
		while (i <= size)
		{
			my_drawer(i, size);
			i++;
		}
		my_trunk(size);
	}
}

int main(int ac, char **av)
{
	tree(my_atoi(av[1]));
}
