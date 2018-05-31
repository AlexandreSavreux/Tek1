/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include "my.h"
#include "hangman.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int check_one_word(char *str)
{
	for (int j = 0; str[j] != '\0'; j++) {
		if (str[j] <= ' ' || str[j] >= 127)
			return (1);
	}
}

char **check_words(char **array)
{
	if (array == NULL)
		return (NULL);
	for (int i = 0; array[i] != NULL; i++) {
		if (check_one_word(array[i]))
			return (NULL);
	}
	return (array);
}

hangman_t *prepare_my_struct(int nb, char **array)
{
	int random;
	hangman_t *ret = calloc(1, sizeof(hangman_t));
	int i = 0;

	srand((unsigned int)getpid());
	random = rand() % my_arrlen(array);
	ret->to_found = strdup(array[random]);
	ret->result = my_strdup(ret->to_found);
	while (ret->result[i] != '\0') {
		ret->result[i] = '*';
		i++;
	}
	if (nb == 0)
		ret->tries = 10;
	else
		ret->tries = nb;
	return (ret);
}