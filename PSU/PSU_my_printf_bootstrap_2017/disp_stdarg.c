/*
** EPITECH PROJECT, 2017
** disp_starg.c
** File description:
** function to display sum_stdarg
*/
#include <stdarg.h>
#include "my.h"

int disp_stdarg(char *s, ...)
{
	va_list va;
	int res = 0;
	int index = 0;
	char i = s[index];

	va_start(va, my_strlen(s));
	switch (i) {
	case 'c' :
		my_putchar(va_arg(va, int));
		index++;
		break;
	case 's' :
		my_putstr(va_arg(va, char*));
		index++;
		break;
	case 'i' :
		my_put_nbr(va_arg(va, int));
		index++;
		break;
	}
	va_end(va);
	return (0);
}
