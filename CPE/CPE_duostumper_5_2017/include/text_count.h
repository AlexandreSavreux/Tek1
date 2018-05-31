/*
** EPITECH PROJECT, 2022
** CPE_duostumper_5_2017
** File description:
** Created by Florian Louvet,
*/
#ifndef CPE_DUOSTUMPER_5_2017_TEXT_COUNT_H
#define CPE_DUOSTUMPER_5_2017_TEXT_COUNT_H

typedef struct occurence_s {
	int *nb_of_occurences;
	char *character;
} occurence_t;

char *int_to_str(int nbr);

//char **my_counter(const char *str, const char *to_search, occurence_t *occu);


char **select_option(const char *str, const char *to_search, occurence_t *occu);

char **my_counter(const char *str, occurence_t *occu);

char **my_counter_with_arg(const char *str, const char *to_search,
	occurence_t *occu
);

int len_int(int *src);

int get_r_arg(char **array);

int get_t_arg(char **array);

int *get_the_nb(int nb, int *src);

int **get_occurence(occurence_t *occurence);

int get_the_good_value(char c, char **arr);

#endif //CPE_DUOSTUMPER_5_2017_TEXT_COUNT_H
