/*
** EPITECH PROJECT, 2022
** CPE_lemin_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void check_cmds(char *line, room_t *anthil)
{
	if (my_strstr("##start", line) && anthil->cmd == 0) {
		anthil->cmd = START;
		my_printf("##end\n");
	} else if (my_strstr("##end", line) && anthil->cmd == 0) {
		anthil->cmd = END;
		my_printf("##start\n");
	}
}

int get_room(char **map, int *i, room_t *anthil)
{
	int space = 0;
	char **line = NULL;

	if (map[*i][0] == '#') {
		if (map[*i][1] == '#') {
			check_cmds(map[*i], anthil);
		}
	}
	for (int j = 0; map[*i][j] != '\0'; j++)
		(map[*i][j] == ' ') ? space++ : 0;
	if (space == 2) {
		line = my_str_to_wordarray(map[*i], ' ');
		anthil->name = line[0];
		anthil->x = my_atoi(line[1]);
		anthil->y = my_atoi(line[2]);
		my_printf("%s %d %d\n", anthil->name, anthil->x, anthil->y);
	}
	return (0);
}

int get_number_of_ants(char **map)
{
	int nb_ants = 0;

	if (map[0] != NULL && my_str_isnum(map[0])) {
		nb_ants = my_atoi(map[0]);
		my_printf("#number_of_ants\n%d\n#rooms\n", nb_ants);
		return (0);
	}
	return (1);
}

int my_openner(room_t *anthil)
{
	char buffer[4096];
	char **map = NULL;
	int j = 0;
	int n = 0;

	while (read(0, buffer, 4096) > 0) {
		map = my_str_to_wordarray(buffer, '\n');
	}
	if (get_number_of_ants(map))
		return (84);
	for (int i = 0; map[i] != NULL; i++) {
		if (get_room(map, &i, anthil))
			return (84);
		n = check_str(map[i]);
		if (n == 1 && j == 1)
			my_printf("%s\n", map[i]);
		if (n == 1 && j == 0) {
			my_printf("#tunnels\n");
			my_printf("%s\n", map[i]);
			j = 1;
		}
	}
	return (0);
}
