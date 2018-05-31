/*
** EPITECH PROJECT, 2017
** my_list_size.c
** File description:
** Returns the size of the list
*/

#include <stdlib.h>
#include "mylist.h"
#include "my.h"

int my_list_size (linked_list_t const *begin)
{
	int i = 0;

	for (begin != NULL; i++)
		begin = begin->next;
	return (i);
}
