/*
** EPITECH PROJECT, 2017
** main.c
** File description:
** Main for bistro-matic
*/
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "include/bistro-matic.h"
#include "include/my.h"

static void check_base(char const *base);
static void check_ops(char const *ops);
static char *get_expr(unsigned int size);

static void check_base(char const *b)
{
	if (my_strlen(b) < 2) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_BASE);
	}
}

static char *get_expr(unsigned int size)
{
	char *expr;

	if (size <= 0) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_SIZE_NEG);
	}
	expr = malloc(size + 1);
	if (expr == 0) {
		my_putstr(ERROR_MSG);
		exit(EXIT_MALLOC);
	}
	if (read(0, expr, size) != size) {
		my_putstr(ERROR_MSG);
		exit(EXIT_READ);
	}
	expr[size] = 0;
	return (expr);
}

static void check_ops(char const *ops)
{
	if (my_strlen(ops) != 7) {
		my_putstr(SYNTAX_ERROR_MSG);
		exit(EXIT_OPS);
	}
}

int main(int ac, char **av)
{
	int size;
	char *expr;

	size = my_atoi(av[3]);
	expr = get_expr(4);
	my_putstr(eval_expr(expr));
	return (EXIT_SUCCESS);
}
