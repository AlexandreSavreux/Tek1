/*
** EPITECH PROJECT, 2017
** my_print_params.c
** File description:
** Displays arguments received on the command line
*/

int main(int argc, char **argv )
{
	int i = 0;

	while(argv[i] != '\0') {
		my_putstr(argv[i]);
		my_putchar('\n');
		i++;
	}
	return (0);
}
