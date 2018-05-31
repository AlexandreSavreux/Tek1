/*
** EPITECH PROJECT, 2017
** puissance
** File description:
** calcule 10^j
*/

int puissance(int j)
{
	int res = 10;
	int i;

	if (j == 0)
		return (1);
	for (i = 1; i < j; i++)
		res = res * 10;
	return (res);
}
