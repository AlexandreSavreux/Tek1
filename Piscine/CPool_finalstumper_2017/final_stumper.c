/*
** EPITECH PROJECT, 2017
** final_stumper.c
** File description:
** Return the arguments whitch are matching into rush1 execs
*/
#include <unistd.h>
#include "include/my.h"

int printer(int nb, int col, int line)
{
	switch (nb) {
	case 1 :
		my_putstr("[rush1-5] ");
		my_put_nbr(col);
		my_putchar(' ');
		my_put_nbr(line);
		if (col == 1 || line == 1)
			return (0);
		else
			my_putchar('\n');
		return (0);
	case 2 :
		my_putstr("[rush1-4] ");
		my_put_nbr(col);
		my_putchar(' ');
		my_put_nbr(line);
		if (col == 1 || line == 1)
			return (0);
		else
			my_putchar('\n');
		return (0);
	case 3 :
		my_putstr("[rush1-3] ");
		my_put_nbr(col);
		my_putchar(' ');
		my_put_nbr(line);
		if (col == 1 || line == 1)
			return (0);
		else
			my_putchar('\n');
		return (0);
	}
}

int exeptions(char *str, int line, int col)
{
	char check = str[0];

	if (check == 'o') {
		my_putstr("[rush1-1] ");
		my_put_nbr(col);
		my_putchar(' ');
		my_put_nbr(line);
		my_putchar('\n');
		return (0);
	}
	else if (check == '*' || check == '/') {
		my_putstr("[rush1-2] ");
		my_put_nbr(col);
		my_putchar(' ');
		my_put_nbr(line);
		my_putchar('\n');
		return (0);
	}
	return (1);
}

int exeptions2(char *str,int line, int col, int offset)
{
	if (str[offset - 2] == 'A') {
		return (printer(1, col, line));
	}
	else if (str[(offset - (col + 1))] == 'A') {
		return (printer(2, col, line));
	}
	else if (str[col - 1] == 'A') {
		return (printer(3, col, line));
	}
	else if (col == 1 && str[offset - 2] == 'B') {
		printer(3, col, line);
		my_putstr(" || ");
		printer(2, col, line);
		my_putstr(" || ");
		printer(1, col, line);
		my_putchar('\n');
	}
	return (1);
}

void rush3(char *str)
{
	int x = 0;
	int y = 0;
	int i = 0;
	int offset;
	int line = 1;
	int col = 1;

	for (offset = 0; str[offset] != '\0'; offset++);
	while (col * line + line != offset) {
		if (str[col] == '\n') {
			line++;
			col = 0;
		}
		col++;
	}
	exeptions(str, line, col);
	exeptions2(str, line, col, offset);
}

