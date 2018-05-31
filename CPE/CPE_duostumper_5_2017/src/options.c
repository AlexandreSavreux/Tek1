/*
** EPITECH PROJECT, 2022
** CPE_duostumper_5_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"
#include "text_count.h"
#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

char **select_option(const char *str, const char *to_search, occurence_t *occu)
{
	char **res;

	switch (to_search[0]) {
	case '\0':
		res = my_counter(str, occu);
		break;
	default:
		res = my_counter_with_arg(str, to_search, occu);
	}
	return (res);
}