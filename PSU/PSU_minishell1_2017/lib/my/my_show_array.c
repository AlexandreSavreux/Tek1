/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"

void my_show_array(char **array)
{
	for (int i = 0; array[i] != NULL; i++)
		my_printf("ARR: %s\n", array[i]);
}