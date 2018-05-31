/*
** EPITECH PROJECT, 2017
** my_is_prime.c
** File description:
** Returns 1 if is a whole number and 0 if not
*/
int my_condition_loop (int nb, int c, int i)
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

int     my_square_root_2(int nb)
{
	int i = 0;
	int c = 0;
	int result = 0;

	result = my_condition_loop( nb, c, i);
	return (result);
}

int my_is_prime(int nb)
{
	int a = nb;

	if (nb < 2)
		return (0);
	if (nb == 3)
		return (1);
	for (int i = 2 ; i <= my_square_root_2(a) ; i++) {
		if ( (nb % i) != 0) {
			return (1);
		}
	}
	return (0);
}
