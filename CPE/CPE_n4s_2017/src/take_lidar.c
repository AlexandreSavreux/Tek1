/*
** EPITECH PROJECT, 2022
** CPE_n4s_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include <stddef.h>
#include "my.h"
#include <stdio.h>
#include "n4s.h"

float *take_lidar(float *value)
{
	char **array = NULL;
	char *answer = NULL;

	answer = send_command(com_command[INFO_LIDAR], 0);
	array = str_to_array(answer, ':');
	for (int i = 3; array[i + 1] != NULL && (i - 3) != 32; i++) {
		value[i - 3] = atof(array[i]);
		value[i - 2] = -1;
	}
	free_array(array);
	return (value);
}