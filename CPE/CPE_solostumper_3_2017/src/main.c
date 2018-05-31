/*
** EPITECH PROJECT, 2022
** CPE_solostumper_3_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_printer(int result, int a)
{
	switch (result) {
	case 1:
		printf("Fuzz\n");
		break;
	case 2:
		printf("Bozz\n");
		break;
	case 3:
		printf("FuzzBozz\n");
		break;
	default:
		printf("%d\n", a);
	}
}

void calc(char **av)
{
	int a = atoi(av[1]);
	int b = atoi(av[2]);
	int result = 0;
	float div_p2;
	float div_p3;

	while (a <= b) {
		div_p2 = a % 2;
		div_p3 = a % 3;
		if (div_p2 == 0.000000 && div_p3 == 0.000000)
			result = 3;
		else if (div_p3 == 0.000000)
			result = 2;
		else if (div_p2 == 0.000000)
			result = 1;
		my_printer(result, a);
		result = 0;
		a++;
	}
}

int check_errors(int ac, char **av)
{
	if (ac != 3 || my_str_isnum(av[1]) == 0 || my_str_isnum(av[2]) == 0)
		return (1);
	if (atoi(av[1]) > atoi(av[2])) {
		my_puterror("Error: the second parameter must be");
		my_puterror("greater than the first one.\n");
		return (1);
	}
	return (0);
}

int main(int ac, char **av)
{
	if (check_errors(ac, av) == 1)
		return (84);
	calc(av);
	return (0);
}