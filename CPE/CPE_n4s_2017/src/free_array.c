/*
** EPITECH PROJECT, 2022
** CPE_n4s_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include <malloc.h>

void free_array(char **array)
{
	if (array == NULL)
		return;
	for (int i = 0; array[i] != NULL; i++)
		free(array[i]);
	free(array);
}