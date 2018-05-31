/*
** EPITECH PROJECT, 2018
** get_name_comment
** File description:
** get_name_comment
*/

#include "project.h"
#include "my.h"

char *modify_str(char *str)
{
	int i = 1;

	while (str[i - 1] != 34 && str[i] != '\0')
		i++;
	str = &str[i];
	str[my_strlen(str) - 2] = '\0';
	return (str);
}

int get_name_comment(FILE *fd, char **name, char **comment)
{
	char *str = NULL;
	char *res = NULL;
	size_t n = 0;

	getline(&res, &n, fd);
	while (res != NULL && my_strncmp(res, ".name", 5) != 0)
		getline(&res, &n, fd);
	if (res == NULL)
		return (0);
	res = modify_str(res);
	*name = res;
	getline(&str, &n, fd);
	while (str != NULL && my_strncmp(str, ".comment", 8) != 0)
		getline(&str, &n, fd);
	if (str == NULL)
		return (0);
	str = modify_str(str);
	*comment = str;
	return (0);
}
