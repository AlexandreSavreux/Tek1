/*
** EPITECH PROJECT, 2022
** CPE_duostumper_7_2017
** File description:
** Created by Florian Louvet,
*/
#include <memory.h>
#include "my.h"
#include "hangman.h"

void end_game(int status)
{
	switch (status) {
	case 1:
		my_printf("Congratulations!\n");
		break;
	case 0:
		my_printf("You lost!\n");
		break;
	default:
		return;
	}
}

int check_if_match(hangman_t *data, char letter)
{
	int letter_matching = 0;

	for (int i = 0; data->to_found[i] != '\0'; i++) {
		if (data->to_found[i] == letter) {
			data->result[i] = letter;
			letter_matching++;
		}
	}
	if (letter_matching == 0) {
		my_printf("%c: is not in this word\n");
	}
}