/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

typedef struct wordarr_s {
	int i;
	int j;
	int tmp;
} wordarr_t;

int my_str_no_print(char *str, char c, char cbis)
{
	int i = 0;
	int j = 1;

	if (str[0] == '\0')
		return (0);
	while (str[i] != '\0') {
		if (str[i] == c || str[i] == cbis)
			j++;
		i++;
	}
	return (j);
}

int get_str(wordarr_t *node, int locate, char **res, char *str)
{
	while (node->tmp != node->i) {
		res[node->j][locate] = str[node->tmp];
		locate++;
		node->tmp++;
	}
	return (locate);
}

wordarr_t init_node(wordarr_t *node, char *str, char c, char cbis)
{
	node->i = 1;
	node->j = -1;
	if (str != NULL)
		node->tmp = my_str_no_print(str, c, cbis);
	else
		node->tmp = 0;
	return (*node);
}

char **set_res(char **res, wordarr_t *node, char *str)
{
	res = malloc(sizeof(char *) * (node->tmp + 1));
	res[node->tmp] = NULL;
	if (res == NULL)
		return (NULL);
	if (str == NULL)
		return (NULL);
	return (res);
}

char **my_str_to_word_array(char *str, char c, char cbis)
{
	int locate = 0;
	char **res;
	wordarr_t nd = init_node(&nd, str, c, cbis);

	if (my_strcmp(str, my_strdup("\n")) == 0)
		return (special_array());
	res = set_res(res, &nd, str);
	if (res == NULL)
		return (NULL);
	nd.tmp = 0;
	while (str[++nd.i - 1] != '\0')
		if (str[nd.i] == c || str[nd.i] == cbis || str[nd.i] == '\0') {
			nd.j++;
			res[nd.j] = malloc(sizeof(char) * nd.i - nd.tmp + 1);
			locate = get_str(&nd, locate, res, str);
			res[nd.j][locate] = '\0';
			nd.tmp++;
			locate = 0;
		}
	return (res);
}