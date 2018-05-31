/*
** EPITECH PROJECT, 2022
** CPE_duostumper_1_2017
** File description:
** Error handling
*/
#include "my.h"

static int check_second_chain(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '.' && str[i] != '@') {
			my_puterror("Bad char in second chain\n");
			return (1);
		}
	}
}

static int check_first_chain(char *str)
{
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] != '.' && str[i] != '@' && str[i] != '#') {
			my_puterror("Bad char in first chain\n");
			return (1);
		}
	}
}

static int check_before_at(char *str)
{
	char **tab = my_str_to_word_array(str, '@', '@');
	int i = 0;
	int len_tmp = 0;
	int tmp = 0;

	for (tmp; tab[tmp] != NULL; tmp++);
	while (i < tmp) {
		if (len_tmp != 0 && my_strlen(tab[i]) != len_tmp) {
			my_puterror("Invalid patterns\n");
			return (1);
		}
		len_tmp = my_strlen(tab[i]);
		i++;
	}
	return (0);
}

static int check_validity_of_arguments(char **av)
{
	int i = 2;

	if (!my_str_isnum(av[1]) || check_first_chain(av[2]) ||
		check_second_chain(av[3]))
		return (1);
	while (av[i] != NULL) {
		if (check_before_at(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int error_handling_core(int ac, char **av)
{
	if (ac != 4) {
		my_puterror("Invalid number of arguments\n");
		return (84);
	}
	if (my_getnbr(av[1]) < 0) {
		my_puterror("Invalid number\n");
		return (84);
	}
	if (check_validity_of_arguments(av))
		return (84);
	return (0);
}