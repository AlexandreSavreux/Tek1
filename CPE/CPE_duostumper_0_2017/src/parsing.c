/*
** EPITECH PROJECT, 2022
** CPE_my_rpg_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"
#include "struct.h"
#include "ginger.h"

static int error_handling(int ac, char **av)
{
	if (ac != 5)
		return (84);
}

static int len_if_letter(char **str)
{
	int count = 0;

	for (int i = 0; str[i] != NULL; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] != '.')
				count++;
		}
	}
	return (count);
}

int core_parser(int ac, char **av, int fd)
{
	char **str = get_my_file(av[1]);
	pos_t pos[len_if_letter(str)];
	int index = 0;

	for (int i = 0; str[i] != NULL; i++) {
		for (int j = 0; str[i][j] != '\0'; j++) {
			if (str[i][j] != '.') {
				pos[index].x = i;
				pos[index].y = j;
				index++;
			}
		}
	}
}