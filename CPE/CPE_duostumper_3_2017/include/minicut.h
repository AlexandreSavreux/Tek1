/*
** EPITECH PROJECT, 2018
** minicut
** File description:
** minicut
*/

#ifndef MINICUT_H_
	#define MINICUT_H

typedef struct arg_s {
	int *characters;
	char delimiter;
	int *fields;
} arg_t;

void my_characters_opt(arg_t *opts, char **file);

char **my_delim_opt(arg_t *opts, char *file);

void my_field_opt(arg_t *opts, char **file);

#endif
