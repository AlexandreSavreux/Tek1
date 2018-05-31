/*
** EPITECH PROJECT, 2017
** my_pushswap.h
** File description:
** Define linked list and functions made
*/

#ifndef MY_PUSHSWAP_H_
#define MY_PUSHSWAP_H_

typedef struct lk_list
{
	int          c;
	struct lk_list *next;
} t_list;


t_list *add_to_list(t_list *list, int nb);
int my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_putchar(char c);
int pa(t_list **l_a, t_list **l_b);
int pb(t_list **l_a, t_list **l_b, signed short int);
void sa(t_list **l_a, signed short int begin);
int my_atoi(char *str);
#endif
