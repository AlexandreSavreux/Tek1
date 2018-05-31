/*
** EPITECH PROJECT, 2017
** my_find_prime_sup.c
** File description:
** Find the smallest greater prime number
*/

int my_loop_condition (int nb, int c, int i)
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
}

int     my_square_root (int nb)
{
	int i = 0;
	int c = 0;
	int result = 0;

	result = my_loop_condition( nb, c, i);
	return (result);
}

int my_is_prime2 (int nb)
{
	int a = nb;

	if (nb < 2)
		return (0);
	if (nb == 3)
		return (1);
	for (int i = 2 ; i <= my_square_root(a) ; i++) {
		if ( (nb % i) != 0) {
			return (1);
		}
	}
	return (0);
}

int my_find_prime_sup (int nb)
{
	if (nb > 2 && nb % 2 == 0)
		nb = nb + 1;
	while (!my_is_prime2(nb))
		nb = nb + 2;
	return (nb);
}
