/*
** EPITECH PROJECT, 2017
** my_pushswap.c
** File description:
** Main functions for pushswap
*/
#include <stdlib.h>
#include "my_pushswap.h"

void my_show_list(t_list **list)
{
	t_list *tmp;

	tmp = *list;
	while (tmp != NULL) {
		my_put_nbr(tmp->c);
		my_putchar(' ');
		tmp = tmp->next;
	}
	my_putchar('\n');
}
