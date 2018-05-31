/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

int check_hit(player_t *player, int x, int y)
{
	if (player->map[y - 1][(x - 1) * 2] == '.' ||
		player->map[y - 1][(x - 1) * 2] == 'o' ||
		player->map[y - 1][(x - 1) * 2] == 'x') {
		my_putstr(": missed\n");
		my_sender(player->pid, 0);
		usleep(1000);
		my_sender(player->pid, 1);
		return (1);
	} else if (player->map[y - 1][(x - 1) * 2] != '.') {
		my_putstr(": hit\n");
		my_sender(player->pid, 0);
		usleep(1000);
		my_sender(player->pid, 0);
		usleep(1000);
		my_sender(player->pid, 1);
		return (2);
	}
	return (0);
}

static void launched(player_t *player)
{
	int x;
	int y;

	my_putstr("\nwaiting for enemy's attack...\n");
	my_glob = 0;
	while (my_glob == 0)
		pause();
	x = my_glob;
	pause();
	while (my_glob == 0)
		pause();
	y = my_glob;
	my_printf("%c%c", x + 'A' - 1, y + '1' - 1);
	check_hit(player, x, y);
	def_x(player, x, y);
}

static int next(player_t *player)
{
	char *s;

	while (42) {
		launched(player);
		if (victory(player->map) == 1)
			return (1);
		s = turn();
		if (translate(player, s) == 1)
			return (-1);
		my_glob = 0;
		while (my_glob == 0)
			pause();
		make_vs_map(player, s[0] - 'A', s[1] - '0');
		if (victory(player->vs_map) == 1)
			return (0);
		free(s);
		my_map_drawer(player, 1);
	}
}

static int start(player_t *player)
{
	int i;

	my_listener();
	pause();
	my_glob = 0;
	my_putstr("successfully connected\n");
	my_printf("my_pid:  %d\n", getpid());
	my_map_drawer(player, 0);
	i = next(player);
	return (i);
}

int player2(player_t *player, int pid, char *str)
{
	int i = 0;

	if ((player->map = prepare_my_map("src/map", 9, 17)) == NULL)
		return (-1);
	if ((player->vs_map = prepare_my_map("src/map", 9, 17)) == NULL)
		return (-1);
	if ((player->pos = prepare_my_map(str, 5, 9)) == NULL)
		return (-1);
	if (check_pos(player->pos) == -1)
		return (-1);
	while (player->pos[i] != NULL)
		if ((player->map = analyse_map(
			my_str_to_wordarray(player->pos[i++], ':'),
			player->map)) == NULL)
			return (-1);
	if (my_sender(pid, 1) == -1)
		return (-1);
	my_array_free(player->pos);
	player->pid = pid;
	i = start(player);
	return (i);
}