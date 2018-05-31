/*
** EPITECH PROJECT, 2022
** CPE_duostumper_4_2017
** File description:
** Created by tiflo,
*/
#ifndef CPE_DUOSTUMPER_4_2017_DATABASE_H
#define CPE_DUOSTUMPER_4_2017_DATABASE_H

typedef struct database_s {
	int id_movie;
	char title[32];
	char synopsis[128];
	int id_director;
	char director[6];
	int id_type;
	char type[16];
} database_t;

int match(char const *s1, char const *wanted);

database_t *get_info(char **);

#endif //CPE_DUOSTUMPER_4_2017_DATABASE_H
