/*
** EPITECH PROJECT, 2017
** my_swap
** File description:
** swap two integers
*/
void my_swap (int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
