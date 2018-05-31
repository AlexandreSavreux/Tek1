/*
** EPITECH PROJECT, 2017
** Make-main
** File description:
** Pre-made main.c
*/
#include "my.h"
#include "minicut.h"

static void init_struct(arg_t *opts)
{
	opts->characters = malloc(sizeof(int) * 10);
	opts->fields = malloc(sizeof(int) * 10);

	opts->characters[0] = 1;
	opts->delimiter = ':';
	opts->fields[0] = 1;
}

int main(int ac, char **av)
{
	char *tmp = read_fullfile(0);
	arg_t opts;

	init_struct(&opts);
	//my_characters_opt(&opts, my_str_to_word_array(tmp, '\n', '\n'));
	my_field_opt(&opts, my_str_to_word_array(tmp, '\n', '\n'));
	//my_show_array(tmp);
}
