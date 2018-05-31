/*
** EPITECH PROJECT, 2022
** CPE_duostumper_7_2017
** File description:
** Created by Florian Louvet,
*/
#ifndef CPE_DUOSTUMPER_7_2017_HANGMAN_H
#define CPE_DUOSTUMPER_7_2017_HANGMAN_H

typedef struct hangman_s {
	int tries;
	char *to_found;
	char *result;
} hangman_t;

char **get_my_file(char *);

hangman_t *prepare_my_struct(int nb, char **array);

void end_game(int status);

int check_if_match(hangman_t *data, char letter);

int game(hangman_t *data);

char **check_words(char **array);

#endif //CPE_DUOSTUMPER_7_2017_HANGMAN_H