/*
** EPITECH PROJECT, 2018
** CPE_duostumper4
** File description:
** Created by dosukun,
*/

#include "database.h"
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char **parse(char **arr)
{
	int i = 0;
	char *str;
	char *tmp;

	while (arr[i] != NULL) {

		i++;
		free(str);
		free(tmp);
	}
	return (arr);
}

database_t adding_struct(char *str)
{
	char **arr = my_str_to_wordarray(str, ';');
	database_t node;

	my_show_array(arr);
	node.id_movie = atoi(arr[0]);
	if (strlen(arr[1]) < 32)
		strcpy(node.title, arr[1]);
	if (strlen(arr[2]) < 128)
		strcpy(node.synopsis, arr[2]);
	node.id_director = atoi(arr[3]);
	if (strlen(arr[4]) < 16)
		strcpy(node.director, arr[4]);
	node.id_type = atoi(arr[5]);
	if (strlen(arr[6]) < 16)
		strcpy(node.type, arr[6]);
	return (node);
}

database_t *get_info(char **arr)
{
	int i = 0;
	database_t *info = calloc((size_t)my_arrlen(arr), sizeof(database_t));

	while (arr[i] != NULL) {
		printf("ici je test ma chaine %d\n", my_strlen(arr[i]));
		info[i] = adding_struct(arr[i]);
		i++;
	}
	info[i].id_movie = -42;
	return (info);
}