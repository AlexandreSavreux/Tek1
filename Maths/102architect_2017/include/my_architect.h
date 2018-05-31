/*
** EPITECH PROJECT, 2017
** my_architect.h
** File description:
** All prototypes of functions used for 102architect
*/

#ifndef MY_ARCHITECT_H_
#define MY_ARCHITECT_H_

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int check_other(char **av, int n);
int check_arguments(char **av, int n);
int check_xy(int ac, char **av);
int check_all(char **av);
int check_error(int ac, char **av);
double my_filler(double *matrice, double x, double y, char type);
void my_print_ma(double *matrice);
double *mult_matrices(double *matrice, double *ma2);
void my_subcommands(double *result, double *matrice, char **av, int ac);
double *my_translation(double *result, double *matrice, char **av, int i);
double *my_rotation(double *result, double *matrice, char **av, int i);
double *my_symetrie(double *result, double *matrice, char **av, int i);
double *my_homothety(double *result, double *matrice, char **av, int i);
#endif
