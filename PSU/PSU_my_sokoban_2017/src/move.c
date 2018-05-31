/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by tiflo,
*/
#include "sokoban.h"

void move_box(char *map, int player, int box_position, int offset)
{
	map[box_position] = ' ';
	map[box_position + offset] = 'X';
	map[player] = ' ';
	map[player + offset] = 'P';
}

int player_move_it(int *player_pos, char *map, int movement, char *backup_map)
{
	int player = *player_pos;
	int *size = map_size(map);
	int offset[4] = {size[0] + 1, -(size[0] + 1), 1, -1};
	int box_position = player + offset[movement];
	int score = 0;

	if (map[box_position + offset[movement]] == ' ') {
		move_box(map, player, box_position, offset[movement]);
		player = get_player_pos(map);
		*player_pos = player;
	}
	if (map[box_position + offset[movement]] == 'O') {
		move_box(map, player, box_position, offset[movement]);
		player = get_player_pos(map);
		*player_pos = player;
		score = 1;
	}
	score = check_score(map, backup_map);
	return (score);
}

int valid_move(int *player_pos, char *map, int movement, char *backup_map)
{
	int player = *player_pos;
	int *size = map_size(map);
	int offset[4] = {size[0] + 1, -(size[0] + 1), 1, -1};
	int score = 0;

	if (map[player + offset[movement]] == ' ') {
		map[player] = ' ';
		map[player + offset[movement]] = 'P';
		player = get_player_pos(map);
		*player_pos = player;
	} else if (map[player + offset[movement]] == 'X') {
		score = player_move_it(&player, map, movement, backup_map);
		*player_pos = player;
	}
	score = check_score(map, backup_map);
	return (score);
}