/*
** EPITECH PROJECT, 2017
** my_pushswap.c
** File description:
** Main functions for pushswap
*/
#include <stdlib.h>
#include "my_pushswap.h"

void swap_list(t_list **l_a, t_list **l_b)
{
	t_list *tmp;
	int i = 1;
	signed short int begin = 1;

	while (i == 1) {
		i = 0;
		tmp = *l_a;
		while ((*l_a)->next != NULL) {
			if ((*l_a)->c > (*l_a)->next->c) {
				sa(l_a, begin);
				begin = 0;
				i = 1;
			}
			pb(l_a, l_b, begin);
			begin = 0;
			tmp = tmp->next;
		}
		while (*l_b != NULL)
			pa(l_a, l_b);
	}
}

t_list *my_put_in_list(t_list *list, int nb)
{
	t_list *elem;
	t_list *tmp;

	elem = malloc(sizeof(t_list));
	elem->c = nb;
	elem->next = NULL;
	if (list == NULL)
		return (elem);
	tmp = list;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return (list);
}

void check_list(t_list **l_a, t_list **l_b, int ac)
{
	t_list *tmp = *l_a;
	int cpt = ac - 2;
	int i = 0;

	while (tmp->next != NULL && tmp->c < tmp->next->c) {
		i++;
		tmp = tmp->next;
	}
	if (i == cpt || ac == 2)
		return;
	else {
		swap_list(l_a, l_b);
	}
}

int main(int ac, char **av)
{
	t_list *l_a = NULL;
	t_list *l_b = NULL;
	int i = 1;
	int nb;

	while (av[i] != NULL)	{
		nb = my_atoi(av[i]);
		l_a = my_put_in_list(l_a, nb);
		i++;
	}
	check_list(&l_a, &l_b, ac);
	my_putchar('\n');
	return (0);
}
