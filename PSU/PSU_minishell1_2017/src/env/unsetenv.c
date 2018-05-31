/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

static int get_var_pos(char **env, char *to_unset)
{
	int pos = 0;

	while (env != NULL && env[pos]) {
		if (my_strncmp(env[pos], to_unset, my_strlen(to_unset)) == 0 &&
			env[pos][my_strlen(to_unset)] == '=') {
			return (pos);
		}
		pos++;
	}
	return (-1);
}

int my_array_length(char **arr)
{
	int i = 0;

	if (arr == NULL)
		return (0);
	while (arr[i] != NULL)
		i = i + 1;
	return (i);
}

char **del_in_ar(int rem, char **new_arr, char **arr, int len)
{
	int i = 0;
	int j = 0;

	while (i < len) {
		if (i != rem) {
			new_arr[j] = (char *)malloc(
				sizeof(char) * (my_strlen(arr[i]) + 1));
			if (new_arr[j]) {
				my_strcpy(new_arr[j], arr[i]);
				j++;
			}
		}
		i++;
	}
	new_arr[j] = NULL;
	return (new_arr);
}

char **my_remove_from_array(int rem, char **arr)
{
	int len;
	char **new_arr = NULL;

	if (arr != NULL) {
		len = my_array_length(arr);
		new_arr = (char **)malloc(sizeof(char *) * (len));
		new_arr = del_in_ar(rem, new_arr, arr, len);
	}
	return (new_arr);
}

void run_my_unsetenv(char ***env, char *to_unset)
{
	char **new_env = *env;
	int to_unset_pos = get_var_pos(new_env, to_unset);

	if (to_unset_pos > -1) {
		*env = my_remove_from_array(to_unset_pos, *env);
		my_array_free(new_env);
	}
}