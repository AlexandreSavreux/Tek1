/*
** EPITECH PROJECT, 2017
** my_error
** File description:
** check error for arguments
*/

#include <stdio.h>
#include <stdlib.h>
#include "my_architect.h"

int check_other(char **av, int n)
{
	while (av[n] != NULL) {
		if (av[n][1] == 't') {
			if (av[n+1] == NULL && av[n+1][0] == '-') {
				printf("error\n");
				exit (84);
			}
			if (av[n+2] == NULL || av[n+2][0] == '-') {
				printf("error\n");
				exit (84);
                        }
			n = n + 3;
		}
		else if (av[n][1] == 'h') {
			if (av[n+1] == NULL && av[n+1][0] == '-') {
				printf("error\n");
				exit (84);
			}
			if (av[n+2] == NULL || av[n+2][0] == '-') {
				printf("error\n");
				exit (84);
			}
			n = n + 3;
		}
		else if (av[n][1] == 'r') {
			if (av[n+1] == NULL && av[n+1][0] == '-') {
				printf("error\n");
				exit (84);
			}
			if (av[n+2] != NULL) {
				printf("error\n");
				exit (84);
			}
			n = n + 2;
		}
		else if(av[n][1] == 's') {
			if (av[n+1][0] == '-' && av[n+1] == NULL) {
				printf("error\n");
				exit (84);
			}
			if (av[n+2] != NULL) {
				printf("error\n");
				exit (84);
			}
			n = n + 2;
		}
	}
	return (0);
}

int check_arguments(char **av, int n)
{
	int i = 0;

	if (av[n][i] != '-') {
		printf("error\n");
		exit (84);
	}
	i++;
	if (av[n][i] != 't' && av[n][i] != 'h' && av[n][i] != 'r' && av[n][i] != 's') {
		printf("error\n");
		exit (84);
	}
	if (av[n][i+1] != '\0') {
		printf("error\n");
		exit (84);
	}
	check_other(av, n);
	return (0);
}

int	check_xy(int ac, char **av)
{
	int i = 0;
	int n = 1;

	if (ac < 5) {
		printf("error\n");
		exit (84);
	}
	while (n != 3) {
		while (av[n][i] != '\0') {
			if ((av[n][i] >= '0' && av[n][i] <= '9') || av[n][0] == '-')
				i++;
			else {
				printf("error\n");
				exit (84);
			}
		}
		i = 0;
		n++;
	}
	return (0);
}

int check_all(char **av)
{
	int n = 1;
	int i = 0;

	while (av[n] != NULL) {
		if (av[n][0] != '-') {
			while (av[n][i] != '\0') {
				if (av[n][i] < '0' || av[n][i] > '9') {
					printf ("error\n");
					exit (84);
				}
				i++;
			}
			i = 0;
		}
		if (av[n][0] == '-' && av[n][2] != '\0') {
			printf("erorr\n");
			exit (84);
		}
		n++;
	}
	return (0);
}

int check_error(int ac, char **av)
{
	int n = 3;

	check_all(av);
	check_xy(ac, av);
	check_arguments(av, n);
	return (0);
}
