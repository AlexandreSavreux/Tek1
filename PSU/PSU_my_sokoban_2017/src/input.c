/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by tiflo,
*/
#include "sokoban.h"

int player_move(int move, int score, char *map, char *backup_map)
{
	int player_pos = get_player_pos(map);

	if (move == 'A')
		score = valid_move(&player_pos, map, 1, backup_map);
	if (move == 'B')
		score = valid_move(&player_pos, map, 0, backup_map);
	if (move == 'C')
		score = valid_move(&player_pos, map, 2, backup_map);
	if (move == 'D')
		score = valid_move(&player_pos, map, 3, backup_map);
	return (score);
}

int game_logic(char *map, char *backup_map, int score, int play)
{
	int input;

	if (!play) {
		refresh();
		return (score);
	}
	mvprintw(0, 0, map);
	input = getch();
	if (input == -1)
		return (-2);
	score = player_move(input, score, map, backup_map);
	if (input == 32)
		return (-1);
	refresh();
	return (score);
}