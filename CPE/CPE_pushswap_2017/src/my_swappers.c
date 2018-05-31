/*
** EPITECH PROJECT, 2017
** my_swappers.c
** File description:
** All operations useful for pushswap
*/

#include <stdlib.h>
#include "my_pushswap.h"

t_list *add_to_list(t_list *list, int nb)
{
	t_list *tmp;

	tmp = malloc(sizeof(t_list));
	tmp->c = nb;
	tmp->next = list;
	list = tmp;
	return (list);
}

int pa(t_list **l_a, t_list **l_b)
{
	int nb;

	if (*l_b == NULL)
		return (1);
	nb = (*l_b)->c;
	*l_a = add_to_list(*l_a, nb);
	*l_b = (*l_b)->next;
	my_putstr(" pa");
	return (0);
}
int pb(t_list **l_a, t_list **l_b, signed short int begin)
{
	int nb;

	if (*l_a == NULL)
		return (1);
	nb = (*l_a)->c;
	*l_b = add_to_list(*l_b, nb);
	*l_a = (*l_a)->next;
	if (begin == 1)
		my_putstr("pb");
	else
		my_putstr(" pb");
	return (0);
}

void sa(t_list **l_a, signed short int begin)
{
	t_list *tmp;

	tmp = *l_a;
	tmp = tmp->next;
	(*l_a)->next = tmp->next;
	tmp->next = *l_a;
	*l_a = tmp;
	if (begin == 1)
		my_putstr("sa");
	else
		my_putstr(" sa");
}
