/*
** EPITECH PROJECT, 2018
** .
** File description:
** Created by dosukun,
*/

#include "hangman.h"
#include "my.h"
#include <string.h>

char *modify_str(char *str)
{
	if (str[strlen(str) - 1] == '\n')
		str[strlen(str) - 1] = '\0';
	else {
		return (str);
	}
	return (str);
}

char get_the_new_letter(void)
{
	size_t size = 0;
	char *buff = NULL;
	char *res = my_strdup("first");
	char c;

	while (strlen(res) != 1 || my_str_isprintable(res) != 1) {
		my_putstr("Your letter: ");
		if (getline(&buff, &size, stdin) == -1)
			return ('\0');
		buff = modify_str(buff);
		if (strlen(buff) == 1) {
			free(res);
			res = my_strdup(buff);
		}
		free(buff);
		buff = NULL;
	}
	c = res[0];
	if (c <= 'Z' && c >= 'A')
		c += 32;
	return (free(res), c);
}

int game(hangman_t *data)
{
	char c;

	my_printf("%s\nTries: %d\n\n", data->result, data->tries);
	while (strcmp(data->result, data->to_found) != 0 && data->tries != 0) {
		c = get_the_new_letter();
		if (c == '\0')
			return (0);
		check_if_match(data, c);
		if (is_in_str(data->result, c) == 0)
			data->tries--;
		my_printf("%s\nTries: %d\n\n", data->result, data->tries);
	}
	if (strcmp(data->result, data->to_found) == 0)
		end_game(1);
	else
		end_game(0);
}