/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int second_translate(player_t *player, int y)
{
	if (my_sender(player->pid, 1))
		return (-1);
	while (y >= 0) {
		usleep(1000);
		if (my_sender(player->pid, 0) == -1)
			return (-1);
		y--;
	}
	usleep(1000);
	if (my_sender(player->pid, 1) == -1)
		return (-1);
	return (0);
}

int translate(player_t *player, char *s)
{
	int x = -1;
	int y = -1;

	if (s[0] >= 'A' && s[0] <= 'H')
		x = s[0] - 'A';
	if (s[1] >= '1' && s[1] <= '8')
		y = s[1] - '1';
	while (x >= 0) {
		usleep(1000);
		if (my_sender(player->pid, 0) == -1)
			return (-1);
		x--;
	}
	usleep(1000);
	if (second_translate(player, y) == -1)
		return (-1);
	my_putstr(s);
	return (0);
}

void make_vs_map(player_t *player, int x, int y)
{
	switch (my_glob) {
	case 1: {
		my_putstr(": missed\n");
		player->vs_map[y - 1][(x) * 2] = 'o';
		break;
	}
	case 2 : {
		my_putstr(": hit\n");
		player->vs_map[y - 1][(x) * 2] = 'x';
		break;
	}
	}
}

void my_map_drawer(player_t *player, int ennemy)
{
	int i;
	int nb;

	if (ennemy == 0)
		my_putstr("my positions:\n");
	else
		my_putstr("\nmy postions:\n");
	my_putstr(" |A B C D E F G H\n-+---------------\n");
	i = 0;
	nb = 1;
	while (player->map[i] != NULL)
		my_printf("%i|%s", nb++, player->map[i++]);
	my_putstr("\nenemy's positions:\n");
	i = 0;
	nb = 1;
	my_putstr(" |A B C D E F G H\n-+---------------\n");
	while (player->vs_map[i] != NULL)
		my_printf("%i|%s", nb++, player->vs_map[i++]);
}

char **prepare_my_map(char *path, int x, int y)
{
	alloc_t alloc;

	alloc.i = 0;
	if ((alloc.fd = open(path, O_RDONLY)) == -1)
		return (NULL);
	if ((alloc.array1 = (char **)malloc(sizeof(char *) * x)) == NULL)
		return (NULL);
	if ((alloc.array2 = (char *)malloc(sizeof(char) * x * y)) == NULL)
		return (NULL);
	my_memset(alloc.array2, '\0', x * y);
	while (alloc.i < x - 1) {
		alloc.array1[alloc.i] = &alloc.array2[alloc.i * y];
		alloc.array1[alloc.i++][y] = '\0';
	}
	alloc.array1[alloc.i] = NULL;
	alloc.i = 0;
	while (alloc.i < x - 1) {
		if (read(alloc.fd, alloc.array1[alloc.i++], y - 1) == -1)
			return (NULL);
	}
	close(alloc.fd);
	return (alloc.array1);
}
