/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

char *turn(void)
{
	char *s = NULL;

	my_putstr("\nattack: ");
	if ((s = get_next_line(0)) == NULL) {
		my_printf("\nwrong positions");
		return (turn());
	}
	if (my_strlen(s) > 2) {
		my_putstr("wrong positions");
		free(s);
		return (turn());
	}
	if (s[0] < 'A' || s[0] > 'H' || s[1] < '1' || s[1] > '8') {
		my_putstr("wrong positions");
		free(s);
		return (turn());
	}
	return (s);
}

int check_pos2(char **pos, int i)
{
	if (pos[i][0] < '2' && pos[i][0] > '5')
		return (-1);
	if ((pos[i][2] < 'A' && pos[i][2] > 'H') ||
		(pos[i][2] < '1' && pos[i][2] > '8'))
		return (-1);
	if ((pos[i][3] < 'A' && pos[i][3] > 'H') ||
		(pos[i][3] < '1' && pos[i][3] > '8'))
		return (-1);
	if ((pos[i][5] < 'A' && pos[i][5] > 'H') ||
		(pos[i][5] < '1' && pos[i][5] > '8'))
		return (-1);
	if ((pos[i][6] < 'A' && pos[i][6] > 'H') ||
		(pos[i][6] < '1' && pos[i][6] > '8'))
		return (-1);
	return (0);
}

int chek_pos3(char *s)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i]) {
		if (s[i] == ':')
			count = count + 1;
		i++;
	}
	if (count != 2)
		return (-1);
	return (0);
}

int check_len(int len, int i)
{
	if (len != 14) {
		my_puterror("bad boat\n");
		return (-1);
	}
	if (i != 4) {
		my_puterror("bad boat\n");
		return (-1);
	}
	return (0);
}

int check_pos(char **pos)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (pos[i]) {
		if (check_pos2(pos, i) == -1 || chek_pos3(pos[i]) == -1) {
			my_puterror("bad boat\n");
			return (-1);
		}
		len = pos[i++][0] - '0' + len;
	}
	if (check_len(len, i) == -1)
		return (-1);
	return (0);
}