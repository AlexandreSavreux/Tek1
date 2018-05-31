/*
** EPITECH PROJECT, 2022
** CPE_duostumper_5_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"
#include "text_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

static int counter(const char *str, char letter, occurence_t *occu,
	const char *to_compare
)
{
	int pos = 0;
	int nb = 0;
	char lett[2];

	while (str[pos] != '\0') {
		if (str[pos] == letter)
			nb++;
		pos++;
	}
	pos = 0;
	while (occu->character[pos] != '\0')
		pos++;
	lett[0] = letter;
	lett[1] = '\0';
	strcat(occu->character, lett);
	occu->nb_of_occurences[pos] = nb;
	return (nb);
}

static int exist(occurence_t *occu, char to_search)
{
	int pos = 0;

	if (occu->character == NULL)
		return (0);
	while (occu->character[pos] != '\0') {
		if (occu->character[pos] == to_search)
			return (1);
		pos++;
	}
	return (0);
}

char *launch_counter(occurence_t *occu, const char *str, int pos,
	const char *to_compare
)
{
	char *line = malloc(sizeof(char) * strlen(str) + 10);
	char letter[2];

	if (line == NULL)
		return (NULL);
	line[0] = '\0';
	letter[0] = str[pos];
	letter[1] = '\0';
	strcat(line, letter);
	strcat(line, ":");
	if (to_compare != NULL)
		strcat(line,
			int_to_str(counter(str, to_compare[pos], occu, NULL)));
	else
		strcat(line, int_to_str(counter(str, str[pos], occu, NULL)));
	strcat(line, ";");
	return (line);
}

char **my_counter(const char *str, occurence_t *occu)
{
	char *line = NULL;
	char **res = NULL;

	line = malloc(sizeof(char) * strlen(str) + strlen(str) * 2 + 10);
	occu->character = malloc(sizeof(char) * strlen(str) + 1);
	occu->nb_of_occurences = malloc(sizeof(int) * strlen(str) + 1);
	if (line == NULL || occu->character == NULL ||
		occu->nb_of_occurences == NULL)
		return (NULL);
	occu->character[0] = line[0] = '\0';
	for (int pos = 0; str[pos] != '\0'; pos++) {
		if (exist(occu, str[pos]) == 0)
			strcat(line, launch_counter(occu, str, pos, NULL));
	}
	occu->nb_of_occurences[strlen(occu->character) + 1] = -1;
	res = my_str_to_word_array(line, ';', ';');
	res[my_arrlen(res) - 1] = NULL;
	return (free(line), res);
}

char **my_counter_with_arg(const char *str, const char *to_search,
	occurence_t *occu
)
{
	char *line = NULL;
	char **res = NULL;

	line = malloc(sizeof(char) * strlen(str) + strlen(str) * 2 + 10);
	occu->character = malloc(sizeof(char) * strlen(str) + 1);
	occu->nb_of_occurences = malloc(sizeof(int) * strlen(str) + 1);
	if (line == NULL || occu->character == NULL ||
		occu->nb_of_occurences == NULL)
		return (NULL);
	occu->character[0] = line[0] = '\0';
	for (int pos = 0; str[pos] != '\0'; pos++) {
		for (int i = 0; to_search[i] != '\0'; i++)
			(exist(occu, to_search[i]) == 0) ? strcat(line,
				launch_counter(occu, str, i, to_search)) : 0;
	}
	res = my_str_to_word_array(line, ';', ';');
	res[my_arrlen(res) - 1] = NULL;
	occu->nb_of_occurences[strlen(occu->character) + 1] = -1;
	return (free(line), res);
}