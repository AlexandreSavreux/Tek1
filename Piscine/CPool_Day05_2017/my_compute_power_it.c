/*
** EPITECH PROJECT, 2017
** my_compute_power_it.c
** File description:
** Returns the first argument raised to the power p
*/

int my_compute_power_it (int nb, int p)
{
	long r = nb;
	int i = 2;

	while (i <= p) {
		r = r * nb;
		i++;
		if (p == 0)
			return (1);
		if (p < 0 || r >= 2147483647 || r <= -2147483648)
			return (0);
	}
	return (r);
}
