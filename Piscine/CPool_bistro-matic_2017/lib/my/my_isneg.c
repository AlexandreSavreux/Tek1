/*
** EPITECH PROJECT, 2017
** my_isneg.c
** File description:
** Check if a number is negative or not
*/
#include "my.h"

int my_isneg (int n)
{
	if (n < 0) {
		my_putchar(78);
	} else {
		my_putchar(80);
	}
	return (0);
}
