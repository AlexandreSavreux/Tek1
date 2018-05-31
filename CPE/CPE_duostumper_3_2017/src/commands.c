/*
** EPITECH PROJECT, 2022
** CPE_duostumper_3_2017
** File description:
** Created by tiflo,
*/
#include "my.h"
#include "minicut.h"

void my_characters_opt(arg_t *opts, char **file)
{
	int j = 0;

	for (int line = 0; file[line] != NULL; line++) {
		for (int i = 0; opts->characters[i]; i++) {
			my_putchar(file[line][opts->characters[i] - 1]);
		}
		if (file[line + 1])
			my_putchar('\n');
	}
}

char **my_delim_opt(arg_t *opts, char *file)
{
	char **new_file = my_str_to_word_array(file, opts->delimiter,
		opts->delimiter);

	return (new_file);
}

void my_field_opt(arg_t *opts, char **file)
{
	int j = 0;
	char **formated_file = NULL;

	for (int line = 0; file[line + 1] != NULL; line++) {
		if (opts->delimiter)
			formated_file = my_str_to_word_array(file[line],
				opts->delimiter, opts->delimiter);
		for (int i = 0; opts->fields[i] != 0; ++i) {
			my_putstr(my_strncat(formated_file[opts->fields[i - 1]],
				"\0", 1));
		}
		if (file[line + 1])
			my_putchar('\n');
	}
}