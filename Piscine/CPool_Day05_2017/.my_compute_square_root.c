/*
** EPITECH PROJECT, 2017
** my_compute_square_root.c
** File description:
** Returns square root
*/

int my_operations (int nb, int n, int o)
{
	int m;

	if (n * n == nb)
		return (n);
	m = (n + (o - n) / 2);
	if (n < o)
		return (m);
	else {
		if ( m * m > nb)
			return (my_operations( nb, n, m - 1));
		else
			return (my_operations( nb, m + 1, o));
	}
}

int my_compute_square_root (int nb)
{
	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	else
		my_operations(nb, 1, 46340);
}

int main (void)
{
	printf("%d",my_compute_square_root(36));
}
