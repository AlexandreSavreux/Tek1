/*
** EPITECH PROJECT, 2017
** my_compute_factorial_it.c
** File description:
** Returns the factorial of the number given as a parameter
*/

int my_compute_factorial_it (int nb)
{
	int i = nb -1;

	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	while (i > 0) {
		nb = nb * i;
		i--;
	}
	return (nb);
}
