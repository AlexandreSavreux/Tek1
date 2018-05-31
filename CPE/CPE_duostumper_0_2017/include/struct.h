/*
** EPITECH PROJECT, 2022
** CPE_my_rpg_2017
** File description:
** Created by Florian Louvet,
*/
#ifndef CPE_MY_RPG_2017_STRUCT_H
#define CPE_MY_RPG_2017_STRUCT_H

typedef struct pos_s {
	int x;
	int y;
} pos_t;

static const char *message[] = {"Ginger never loses\n",
	"Ginger is too old for taht !\n"};

static const char *letters[] = {"G", "T", "F"};

int core_parser(int ac, char **av, int fd);

#endif //CPE_MY_RPG_2017_STRUCT_H
