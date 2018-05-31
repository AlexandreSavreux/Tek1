/*
** EPITECH PROJECT, 2017
** my_compute_power_rec.c
** File description:
** Same that previous but recursive
*/

int my_compute_power_rec (int nb, int p)
{
	int r;

	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	r = (nb * my_compute_power_rec( nb, p - 1));
	return (r);
}
