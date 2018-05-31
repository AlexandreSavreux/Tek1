/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static char *get_new_env_line(char *to_change, char *new_value)
{
	char *new_env_line = malloc(sizeof(char) *
		(my_strlen(to_change) + my_strlen(new_value) + 2));

	if (new_env_line == NULL)
		exit(EXIT_FAILURE);
	new_env_line = my_strncpy(new_env_line, to_change,
		my_strlen(to_change));
	my_strcat(new_env_line, "=");
	new_env_line = my_strncat(new_env_line, new_value,
		my_strlen(new_value));
	new_env_line = my_strcat(new_env_line, "\0");
	return (new_env_line);
}

static char **add_var(char **env, char *to_change, char *new_value, int env_size
)
{
	int i = 0;
	char **new_env;

	if ((new_env = malloc(sizeof(char *) * (env_size + 2))) == NULL)
		exit(EXIT_FAILURE);
	while (env != NULL && env[i]) {
		new_env[i] = env[i];
		i += 1;
	}
	new_env[i] = malloc(sizeof(char) *
		(my_strlen(to_change) + my_strlen(new_value) + 2));
	if (new_env[i] == NULL)
		exit(EXIT_FAILURE);
	new_env[i] = my_strncpy(new_env[i], to_change, my_strlen(to_change));
	my_strcat(new_env[i], "=");
	new_env[i] = my_strncat(new_env[i], new_value, my_strlen(new_value));
	i += 1;
	new_env[i] = NULL;
	return (new_env);
}

void run_my_setenv(shell_t *shell, char *to_change, char *new_value)
{
	int i = 0;
	char *tmp;
	char **new_env = shell->env;

	while (new_env != NULL && new_env[i]) {
		if (my_strncmp(new_env[i], to_change, my_strlen(to_change)) ==
			0 && new_env[i][my_strlen(to_change)] == '=') {
			tmp = get_new_env_line(to_change, new_value);
			new_env[i] = my_strdup(tmp);
			free(tmp);
			return;
		}
		i++;
	}
	shell->env = add_var(new_env, to_change, new_value, i);
}

