/*
** EPITECH PROJECT, 2022
** CPE_duostumper_4_2017
** File description:
** Created by tiflo,
*/
#include "my.h"
#include "database.h"

void my_print_db_table(database_t *movie, int pos)
{
	printf("%d;\"%s\";\"%s\";%d;\"%s\";%d;\"%s\"", movie[pos].id_movie,
		movie[pos].title, movie[pos].synopsis, movie[pos].id_director,
		movie[pos].director, movie[pos].id_type, movie[pos].type);
}

int my_db_get_str(database_t *movie, char *field, char *value)
{
	if (field == "title")
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].title == value) ?
				my_print_db_table(movie, pos) : 0;
	if (field == "synopsis")
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].synopsis == value) ?
				my_print_db_table(movie, pos) : 0;
	if (field == "director")
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].director == value) ?
				my_print_db_table(movie, pos) : 0;
	if (field == "type") {
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].type == value) ?
				my_print_db_table(movie, pos) : 0;
	} else
		return (1);
}

int my_db_get_int(database_t *movie, char *field, char *value)
{
	if (field == "id_movie")
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].id_movie == atoi(value)) ?
				my_print_db_table(movie, pos) : 0;
	if (field == "id_director")
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].id_director == atoi(value)) ?
				my_print_db_table(movie, pos) : 0;
	if (field == "id_type") {
		for (int pos = 0; movie[pos].id_movie != -42; pos++)
			(movie[pos].id_type == atoi(value)) ?
				my_print_db_table(movie, pos) : 0;
	} else
		return (1);
}

int my_db_show(database_t *movie, int pos, int nb)
{
	if (pos > nb) {
		my_puterror("nb should be higher than pos");
		return (84);
	}
	for (int i = pos - 1; pos < nb; pos++) {
		my_print_db_table(movie, pos);
	}
}