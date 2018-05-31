/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main function for sum_stdarg
*/
#include <stdarg.h>
#include "my.h"

int sum_stdarg(int i, int nb,...)
{
	va_list va;
	int res = 0;

	va_start(va, nb);
	switch (i) {
	case 0 :
		for (int j = 0; j < nb; j++)
			res += va_arg(va, int);
		break;
	case 1 :
		for (int j = 0; j < nb; j++)
			res += my_strlen(va_arg(va, char*));
		break;
	default :
		my_putstr("Invalid");
		return (84);
	}
	va_end(va);
	return (res);
}
