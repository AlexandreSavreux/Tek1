/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

char **cat_balls(pos_t *pos, int len, char **str, char **map)
{
	if (pos->y == pos->y2) {
		while (len > 0) {
			if (pos->x > 14)
				return (NULL);
			if (map[pos->y][pos->x] != '.')
				return (NULL);
			map[pos->y][pos->x] = str[0][0];
			if (pos->x < pos->x2)
				pos->x = pos->x + 2;
			else
				pos->x = pos->x - 2;
			len--;
		}
		return (map);
	}
	return (NULL);
}

void setpos(char **str, pos_t *pos)
{
	if (str[1][0])
		pos->x = (str[1][0] - 'A') * 2;
	if (str[1][1])
		pos->y = str[1][1] - '0' - 1;
	if (str[2][0])
		pos->x2 = (str[2][0] - 'A') * 2;
	if (str[2][1])
		pos->y2 = str[2][1] - '0' - 1;
}

static int checkpos(char **s)
{
	if (s[1][0] >= '1' && s[1][0] <= '8')
		my_evil_str(s[0]);
	if ((s[1][0] < 'A') || (s[1][0] > 'H') || (s[1][1] < '1') ||
		(s[1][1] > '8'))
		return (-1);
	if (s[2][0] >= '1' && s[2][0] <= '8')
		my_evil_str(s[1]);
	if ((s[2][0] < 'A') || (s[2][0] > 'H') || (s[2][1] < '1') ||
		(s[2][1] > '8'))
		return (-1);
	return (0);
}

char **analyse_two(pos_t *pos, int len, char **str, char **player)
{
	if (pos->x == pos->x2) {
		while (len > 0) {
			if (pos->y > 7)
				return (NULL);
			if (player[pos->y][pos->x] != '.')
				return (NULL);
			player[pos->y][pos->x] = str[0][0];
			if (pos->y < pos->y2)
				pos->y++;
			else
				pos->y--;
			len--;
		}
		return (player);
	}
	if (cat_balls(pos, len, str, player) == NULL)
		return (NULL);
	else
		return (player);
	return (NULL);
}

char **analyse_map(char **str, char **map)
{
	int len;
	pos_t pos;

	len = str[0][0] - '0';
	if (checkpos(str) == -1) {
		my_puterror("wrong boat\n");
		my_array_free(str);
		return (NULL);
	}
	setpos(str, &pos);
	if (analyse_two(&pos, len, str, map) == NULL)
		return (NULL);
	return (map);
}