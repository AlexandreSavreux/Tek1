/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_array_free(char **array)
{
	for (int i = 0; array[i]; i++)
		free(array[i]);
	free(array);
}