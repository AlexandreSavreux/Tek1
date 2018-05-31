/*
** EPITECH PROJECT, 2017
** my_compute_factorial_rec.c
** File description:
** same but recursive
*/

int my_compute_factorial_rec (int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0 || nb > 12)
		return (0);
	else
		return nb * my_compute_factorial_rec(nb -1);
}
