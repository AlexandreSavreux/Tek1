/*
** EPITECH PROJECT, 2022
** My_bool.h
** File description:
** Created by tiflo,
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

void va(char **env)
{
	int i = 0;
	int j = 0;
	char *path = NULL;

	while ((*env)[i] != '\0') {
		if ((*env)[i - 1] == '\n' && (*env)[i] == 'P' &&
			(*env)[i + 1] == 'A' && (*env)[i + 2] == 'T' &&
			(*env)[i + 3] == 'H' && (*env)[i + 4] == '=') {
			j = i;
			for (j; (*env)[j] != '\n'; j++);
		}
		i++;
	}
	printf(path);
}

char *my_strncpy(char *dest, char const *src, int n)
{
	for (int i = 0; src[i] != '\0' && n > i; i++) {
		dest[i] = src[i];
	}
	dest[n] = '\0';
	return (dest);
}

void child_process()
{
}

void check_pid()
{
	int pid;

	if ((pid = fork()) == 0)
		child_process();
	else

}

void manage_excec(char *name)
{
	//	execve();
	//fork()
}

void counter_args(char *str, int pos)
{
	int cpt = 0;

	if (str[pos] == '\0')
		return;
	while (str[pos] != '\0') {
		if (str[pos] == ' ')
			cpt++;
		pos++;
	}
	my_printf("Nb args:  %d\n", cpt);
}

void parser(char *str)
{
	int i = 0;
	char *name;

	while (str[i] != ' ' && str[i] != '\0') {
		i++;
	}
	name = malloc(i);
	if (name == NULL)
		exit(84);
	my_strncpy(name, str, i);
	my_printf("Program name:  %s\n", name);
	free(name);
	counter_args(str, i);
	manage_excec(str);
}

int main(int ac, char **av)
{
	//parser(env);
	parser(av[1]);
	return 0;
}