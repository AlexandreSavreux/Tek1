/*
** EPITECH PROJECT, 2017
** my_ls.h
** File description:
** All structures and prototypes used by my_ls
*/
#ifndef MY_LS_H_
#define MY_LS_H_

#include <time.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include "my_ls.h"

typedef struct infos_file_s
{
	mode_t permissions;
	int size_nb_links;
	int size_user;
	int size_group;
	int size_file;
	char *modif_date;
} infos_file_t;

typedef struct list_file_s
{
	char *name;
	mode_t time;
	infos_file_t *infos;
	struct list_file_s *next;
} list_file_t;

typedef struct options_s
{
	char l;
	char R;
	char d;
	char r;
	char t;
	char g;
	char F;
} options_t;

int my_strlen(char const *str);
int my_printf(char *str, ...);
#endif
