/*
** EPITECH PROJECT, 2017
** .h
** File description:
** Pre-made sandpile
*/

#ifndef SAND_PILE_
#define SAND_PILE_

typedef struct vector {
	int x;
	int y;
} vector_t;

char **get_my_file(char *name, char *chara_allowed);
char **if_unstable(const char *allowed_chars, vector_t *pos, vector_t *end,
	char **map);
vector_t *init_end(char **map);
vector_t *init_pos(char **map);
int check_the_line(char *str);


#endif