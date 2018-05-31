/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** Same that previous but recursive
*/

int my_compute_power_rec (int nb, int p)
{
	long r = nb;

	if (p == 0)
		return (1);
	if (p < 0 || r >= 2147483647 || r <= -2147483648)
		return (0);
	r = (nb * my_compute_power_rec( nb, p - 1));
	if (r < 0 || r >= 2147483647 || r <= -2147483648)
		return (0);
	return (r);
}
