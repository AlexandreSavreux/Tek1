/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/

#include "hangman.h"
#include <stdlib.h>
#include "my.h"

int free_that(hangman_t *data, char **array)
{
	if (array != NULL)
		free_array(array);
	if (data != NULL) {
		free(data->to_found);
		free(data->result);
		free(data);
	}
	return (84);
}

int main(int ac, char **av)
{
	char **array = NULL;
	int nb = 0;
	hangman_t *data = NULL;

	if (ac == 2)
		array = get_my_file(av[1]);
	(ac == 3 && my_str_isnum(av[2]) == 1) ?
		(array = get_my_file(av[1]), nb = atoi(av[2])) : 0;
	if (ac == 3 && my_str_isnum(av[1]) == 1) {
		array = get_my_file(av[2]);
		nb = atoi(av[1]);
	}
	if (ac != 2 && array == NULL)
		return (84);
	array = check_words(array);
	if (array == NULL || array[0] == NULL)
		return (free_that(data, array));
	data = prepare_my_struct(nb, array);
	game(data);
	free_that(data, array);
	return (0);
}
