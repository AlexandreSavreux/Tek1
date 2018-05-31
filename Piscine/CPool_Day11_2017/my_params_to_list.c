/*
** EPITECH PROJECT, 2017
** my_params_to_list.c
** File description:
** Creates a new list from the command line arguments
*/

#include <stdlib.h>
#include "my.h"
#include "mylist.h"

linked_list_t *add_to_list(linked_list_t **list, char *value)
{
	linked_list_t added = malloc(sizeof(added));
	if (added == NULL)
		return (0);
	added->data = value;
	added->next = *list;
	return (*list = added);
}

linked_list_t *my_params_to_list(int ac, char const * const *av)
{
	int i = 0;
	linked_list_t *list = NULL;

	while (i < ac) {
		add_to_list(&list, av[i]);
		i++;
	}
	return (list);
}
