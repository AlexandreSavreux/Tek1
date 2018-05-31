/*
** EPITECH PROJECT, 2017
** calc.c
** File description:
** Calc with the operator
*/

#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

int calc(int L, int R, char op)
{
	switch (op) {
	case '+' :
		return (L + R);
	case '-' :
		return (L - R);
	case '*' :
		return (L * R);
	case '/' :
		return (L / R);
	case '%' :
		return (L % R);
	default :
		return (84);
	}
}
