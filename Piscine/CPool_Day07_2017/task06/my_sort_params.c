/*
** EPITECH PROJECT, 2017
** my_sort_params.c
** File description:
** Displays all arguments in ascii order
*/

void	my_str_swap(char **str1, char **str2)
{
	char *stock = *str1;

	*str1 = *str2;
	*str2 = stock;
}

void	my_added_condition(int j, int i, int n, char **argv)
{
	if (n < 0)
		my_str_swap(&argv[j], &argv[i]);
}

int main(int argc, char **argv)
{
	int n;
	int j;
	int i;

	for (j = 0; j < argc; j++) {
		for (i = 0; i < argc; i++) {
			n = my_strcmp(argv[j], argv[i]);
			my_added_condition(j, i, n, argv);
		}
	}
	j = 0;
	while (j < argc) {
		my_putstr(argv[j]);
		my_putchar('\n');
		j++;
	}
	return (0);
}
