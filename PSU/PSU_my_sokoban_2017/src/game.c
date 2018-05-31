/*
** EPITECH PROJECT, 2022
** PSU_my_sokoban_2017
** File description:
** Created by tiflo,
*/
#include "sokoban.h"

int check_score(char *map, char *backup_map)
{
	int score = 0;
	int i = 0;

	while (i < my_strlen(backup_map)) {
		if (backup_map[i] == 'O' && map[i] == 'X') {
			score++;
		}
		if (backup_map[i] == 'O' && map[i] == ' ') {
			map[i] = 'O';
		}
		i++;
	}
	return (score);
}

int check_size(int lines, int cols, char *map)
{
	clear();
	int *m_size = map_size(map);
	char *invalid_size = "Please Resize Window.";
	int size = (my_strlen(invalid_size) / 2);

	if (m_size[0] >= cols || m_size[1] >= lines) {
		mvprintw(lines / 2, cols / 2 - size, invalid_size);
		return (0);
	}
	return (1);
}

int score_win(char *map)
{
	int score = 0;
	int i = 0;

	while (i < my_strlen(map)) {
		if (map[i] == 'O')
			score++;
		i++;
	}
	return (score);
}

int my_sokoban(char *map, char *copy)
{
	int to_win = score_win(map);
	int score = 0;
	int play = 1;

	initscr();
	while (1) {
		play = check_size(LINES, COLS, map);
		score = game_logic(map, copy, score, play);
		if (score == -1 || score == -2)
			break;
		if (score == to_win)
			break;
		refresh();
	}
	endwin();
	if (score == -2)
		exit(1);
	if (score == to_win)
		exit(0);
	return (1);
}