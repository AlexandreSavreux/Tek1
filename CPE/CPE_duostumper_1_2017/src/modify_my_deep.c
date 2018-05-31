/*
** EPITECH PROJECT, 2018
** modify_my_deep
** File description:
** modify_my_deep
*/

#include "my.h"

char **create_array(char **ret, int y)
{
	int tmp = 0;

	ret = malloc(sizeof(char *) * (y + 1));
	ret[y] = NULL;
	return (ret);
}

char *add_a_line(char *hash_line, char *point_line, char *pattern)
{
	int i = 1;
	char *res;
	int more_alloc =
		my_strlen(hash_line) * my_strlen(pattern) - my_strlen(pattern);
	if (pattern[0] == '#')
		res = my_strdup_reac(hash_line, more_alloc);
	else {
		res = my_strdup_reac(point_line, more_alloc);
	}
	while (pattern[i] != '\0') {
		if (pattern[i] == '#') {
			res = my_strcat(res, hash_line);
		} else {
			res = my_strcat(res, point_line);
		}
		i++;
	}
	return (res);
}

char **modify_my_tab(char **hash_tab, char **point_tab, char *trans_str,
	int mode)
{
	char **line = my_str_to_word_array(trans_str, '@', '@');
	int nb_line = my_strlen(line[0]);
	int x = my_strlen(hash_tab[0]) * my_strlen(line[0]);
	int y = my_arrlen(hash_tab) * my_arrlen(line);
	int hash_line = my_arrlen(hash_tab);
	int tmp = 0;
	char **ret = create_array(ret, y);

	if (ret == NULL)
		return (NULL);
	while (tmp != y) {
		ret[tmp] = add_a_line(hash_tab[tmp % hash_line],
			point_tab[tmp % hash_line], line[tmp % nb_line]);
		tmp++;
	}
	if (mode == 1) {
		free_array(hash_tab);
		free_array(point_tab);
	}
	return (ret);
}
