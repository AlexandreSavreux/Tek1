/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_array_free(char **array)
{
	free(array[0]);
	free(array);
}