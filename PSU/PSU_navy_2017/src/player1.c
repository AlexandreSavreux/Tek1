/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void def_x(player_t *player, int x, int y)
{
	if (player->map[y - 1][(x - 1) * 2] == '.' ||
		player->map[y - 1][(x - 1) * 2] == 'o')
		player->map[y - 1][(x - 1) * 2] = 'o';
	else
		player->map[y - 1][(x - 1) * 2] = 'x';
}

static int launched(player_t *player)
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
	if (victory(player->map) == 1)
		return (1);
	my_map_drawer(player, 1);
	return (0);
}

static int next(player_t *player)
{
	char *s;

	while (42) {
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
		if (launched(player) == 1)
			return (1);
	}
}

static int start(player_t *player)
{
	int i;

	my_printf("my_pid:  %d\n", getpid());
	my_putstr("waiting for enemy connexion...\n");
	my_listener();
	pause();
	player->pid = my_glob;
	my_glob = 0;
	if (my_sender(player->pid, 1) == -1)
		return (-1);
	my_putstr("enemy connected\n");
	my_map_drawer(player, 0);
	i = next(player);
	return (i);
}

int player1(player_t *player, char *str)
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
	my_array_free(player->pos);
	i = start(player);
	return (i);
}
