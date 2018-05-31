/*
** EPITECH PROJECT, 2017
** calc.c
** File description:
** Calc with the operator
*/

#include <stdlib.h>
#include "include/my.h"
#include <unistd.h>

char *add(char *s1, char *s2);
char *int_to_string(int nb);

char *calc(char *Li, char* Ri, char op)
{
	long long int R = my_atoi(Ri);
	long long int L = my_atoi(Li);

	switch (op) {
	case '+' :
		return (add(Li , Ri));
	case '-' :
		return (add(Li, Ri));
	case '*' :
		return (int_to_string(L * R));
	case '/' :
		return (int_to_string(L / R));
	case '%' :
		return (int_to_string(L % R));
	default :
		return ("84");
	}
}
