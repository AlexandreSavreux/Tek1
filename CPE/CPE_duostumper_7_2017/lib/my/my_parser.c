/*
** EPITECH PROJECT, 2017
** my_parser.c
** File description:
** Analyse the first argument
*/
#include <stdarg.h>
#include "my.h"

static void my_put_nprintable_char(va_list va)
{
	int i = 0;
	char *str = va_arg(va, char *);

	while (str[i] != '\0') {
		if (str[i] < 32 || str[i] >= 127) {
			my_putstr("\\");
			my_put_nbrbase(str[i], "01234567");
			i++;
		} else {
			my_putchar(str[i]);
			i++;
		}
	}
}

static void my_memory_adress(va_list str)
{
	long long nb = va_arg(str, long long);
	my_putstr("0x");
	my_put_nbrbase(nb, "0123456789abcdef");
}

static int my_flags2(char c, va_list str)
{
	switch (c) {
	case 'b':
		my_put_u_nbrbase(va_arg(str, long long unsigned), "01");
		break;
	case 'S':
		my_put_nprintable_char(str);
		break;
	case 'x':
		my_put_nbrbase(va_arg(str, long long), "0123456789abcdef");
		break;
	case 'X':
		my_put_nbrbase(va_arg(str, long long), "0123456789ABCDEF");
		break;
	default :
		return (1);
	}
	return (0);
}

static void my_flags(char c, va_list str)
{
	if (c == 'd' || c == 'i')
		my_put_nbr(va_arg(str, int));
	switch (c) {
	case 'o':
		my_put_nbrbase(va_arg(str, long long), "01234567");
		break;
	case 'u' :
		my_put_u_nbrbase(va_arg(str, long long unsigned), "0123456789");
		break;
	case 's' :
		my_putstr(va_arg(str, char *));
		break;
	case 'c' :
		my_putchar(va_arg(str, int));
		break;
	case 'p' :
		my_memory_adress(str);
		break;
	default :
		my_flags2(c, str);
	}
}

int my_parser(char *str, va_list va, int a)
{
	char arg;

	if (str[a] == '%') {
		a++;
		while (str[a] == '%') {
			a++;
			my_putchar('%');
		}
		arg = str[a];
		my_flags(arg, va);
	}
	if (str[a - 1] != '%') {
		my_putchar(str[a]);
	}
	a++;
	return (a);
}