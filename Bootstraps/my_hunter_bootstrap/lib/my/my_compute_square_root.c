/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** Displays the square root of the number passed as parameter
*/

int my_condition (int nb, int c, int i)
{
	while (c <= nb)	{
		c = i * i;
		if (c > nb)
			return (i);
		if (c == nb)
			return (i);
		else if (c < 0)
			return (0);
		i++;
	}
	return (i);
}

int     my_compute_square_root(int nb)
{
	int i = 0;
	int c = 0;
	int result = 0;

	result = my_condition( nb, c, i);
	return (result);
}
