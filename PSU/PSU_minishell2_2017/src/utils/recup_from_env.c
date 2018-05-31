/*
** EPITECH PROJECT, 2022
** CPE_tetris_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

char *recup_from_env(char *wanted, char **env)
{
	int i = 0;
	char *str = NULL;

	while (env[i] != NULL) {
		if (my_strncmp(env[i], wanted, my_strlen(wanted)) == 0) {
			str = malloc(sizeof(char) * my_strlen(env[i]) + 1);
			my_strcpy(str, &env[i][my_strlen(wanted)]);
			return (str);
		}
		i++;
	}
	return (NULL);
}