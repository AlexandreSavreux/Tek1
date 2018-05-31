/*
** EPITECH PROJECT, 2022
** CPE_duostumper_6_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"
#include "sandpile.h"

static char change_char(const char *allowed_chars, vector_t *pos, vector_t *end,
	char **map
)
{
	if (map[pos->y][pos->x] == allowed_chars[0]) {
		return (allowed_chars[1]);
	}
	if (map[pos->y][pos->x] == allowed_chars[1]) {
		return (allowed_chars[2]);
	}
	if (map[pos->y][pos->x] == allowed_chars[2]) {
		return (allowed_chars[3]);
	}
	return ('a');
}

char **no_name(vector_t *pos, vector_t *end, char **map,
	const char *allowed_chars
)
{
	static const vector_t DIRECTIONS[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	vector_t *tmp = calloc(1, sizeof(vector_t));
	int boole = 0;
	tmp->x = pos->x;
	tmp->y = pos->y;
	for (int i = 0; i < 4; i++) {
		tmp->x = DIRECTIONS[i].x;
		tmp->y = DIRECTIONS[i].y;
		if ((tmp->x) >= 0 && (tmp->y) >= 0 && tmp->x <= end->x &&
			tmp->y <= end->y) {
			printf("%d Iteration\n", i);
			my_show_array(map);
			my_putchar('\n');
			if (map[pos->y][pos->x] == allowed_chars[3]) {
				map[pos->y][pos->x] = allowed_chars[0];
				if (map[tmp->y][tmp->x] != allowed_chars[3]) {
					map[tmp->y][tmp->x] = change_char(
						allowed_chars, tmp, end, map);

				} else
					boole = 1;
			}

		}
	}
	return (map);
}

char **if_unstable(const char *allowed_chars, vector_t *pos, vector_t *end,
	char **map
)
{
	if (map[pos->y][pos->x] != allowed_chars[3]) {
		map[pos->y][pos->x] = change_char(allowed_chars,
			pos, end, map);
		return (map);
	}
	map = no_name(pos, end, map, allowed_chars);
	return (map);
}