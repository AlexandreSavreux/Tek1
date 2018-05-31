/*
** EPITECH PROJECT, 2022
** CPE_tetris_2017
** File description:
** Created by tiflo,
*/
#include "tetris.h"

static char *recup_value(int pos, char *line)
{
	char *value = malloc(sizeof(char) * my_strlen(line) - pos);

	for (int i = 0; line[i] != '\0'; i++) {
		value[i] = line[pos];
		pos++;
	}
	return (value);
}

static char *check_line(char *wanted, char *line)
{
	int i = 0;

	while (i < my_strlen(wanted)) {
		if (line[i] != wanted[i])
			break;
		i++;
	}
	if (i == my_strlen(wanted))
		return (recup_value(i, line));
	else
		return (NULL);
}

char *recup_from_env(char *wanted, char **env)
{
	int i = 0;
	char *str;

	if (*env == NULL) {
		my_puterror("No environnement\n");
		return (NULL);
	}
	while (env[i] != NULL) {
		if (check_line(wanted, env[i]) != NULL) {
			str = malloc(sizeof(char) *
				my_strlen(check_line(wanted, env[i])));
			my_strcpy(str, check_line(wanted, env[i]));
			return (str);
		}
		i++;
	}
	return (NULL);
}