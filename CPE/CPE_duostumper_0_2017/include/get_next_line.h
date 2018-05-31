/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#ifndef GNL_H_
#define GNL_H_
#ifndef READ_SIZE

#define READ_SIZE 5

struct count_s
{
	int pos;
	int tmp;
	int i;
} count_t;

char *finish(char *);
char *get_error(char buff[]);

#endif
#endif
