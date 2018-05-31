/*
** EPITECH PROJECT, 2017
** my_printf.c
** File description:
** Same as printf in C library
*/
#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int my_printf(char *str, ...)
{
	va_list va;

	va_start(va, str);
	for (int a = 0; str[a] != '\0'; a++) {
		my_parser(str, va, a);
	}
	va_end(va);
	return (0);
}