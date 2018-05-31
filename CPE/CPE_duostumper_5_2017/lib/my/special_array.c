/*
** EPITECH PROJECT, 2018
** special_array
** File description:
** special_array
*/

#include "my.h"
#include <stdlib.h>

char **special_array(void)
{
	char **array = malloc(sizeof(char *) * 2);

	array[0] = my_strdup("\n");
	array[1] = NULL;
	return (array);
}
