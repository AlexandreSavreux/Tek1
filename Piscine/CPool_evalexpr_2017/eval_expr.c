/*
** EPITECH PROJECT, 2017
** eval_expr.c
** File description:
** Manage priorities
*/

#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

int parser(char **str);
int calc(int L, int R, char op);

char *suppr_spaces(char *str)
{
	int i = 0;
	int j = 0;
	char *str2;

	str2 = malloc(my_strlen(str) + 1);
	while (str[i] != '\0') {
		if (str[i] != ' ') {
			str2[j] = str[i];
			j++;
		}
		i++;
	}
	str2[j] = '\0';
	return (str2);
}

int eval_expr_2(char **str)
{
	int Lres = parser(str);
	int Rres;
	char op;

	while ((*str)[0] == '*' || (*str)[0] == '/' || (*str)[0] == '%') {
		op = (*str)[0];
		*str = *str + 1;
		Rres = parser(str);
		Lres = calc(Lres, Rres, op);
	}
	return (Lres);
}

int eval_expr_1(char **str)
{
	int Lres = parser(str);
	int Rres;
	char op;

	while ((*str)[0] != '\0' && (*str)[0] != ')') {
		op = (*str)[0];
		*str = *str + 1;
		if (op == '+' || op == '-')
			Rres = eval_expr_2(str);
		else
			Rres = parser(str);
		Lres = calc(Lres, Rres, op);
	}
	return (Lres);
}

int parser(char **str)
{
	int nb = 0;
	int is_pos = 1;

	if ((*str)[0] == '+' || (*str)[0] == '-') {
		if ((*str)[0] == '-')
			is_pos = -1;
		*str = *str + 1;
	}
	if ((*str)[0] == '(') {
		*str = *str + 1;
		nb = eval_expr_1(str);
		if ((*str)[0] == ')')
			*str = *str + 1;
		return (is_pos * nb);
	}
	while('0' <= (*str)[0] && (*str)[0] <= '9') {
		nb = (nb * 10) + (*str)[0] - '0';
		*str = *str + 1;
	}
	return (is_pos * nb);
}

int eval_expr(char *str)
{
	str = suppr_spaces(str);
	if (str[0] == '\0') {
		write(2, "Invalid output\n", 15);
		return (84);
	}
	return (eval_expr_1(&str));
}
