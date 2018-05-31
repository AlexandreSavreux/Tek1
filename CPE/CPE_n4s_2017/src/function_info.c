/*
** EPITECH PROJECT, 2018
** function_info.c
** File description:
** function for info
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <wait.h>
#include "my.h"
#include "n4s.h"

void free_struct(info_s *info)
{
	free(info->distance);
	free(info);
}

float get_info_float(command_t command)
{
	float speed = 0.0;
	char *answer = NULL;
	char **array = NULL;

	answer = send_command(command, 0);
	array = str_to_array(answer, ':');
	speed = atof(array[3]);
	free_array(array);
	return (speed);
}

info_s *update_info(info_s *info)
{
	info->speed = get_info_float(com_command[CURRENT_SPEED]);
	info->rotation = get_info_float(com_command[CURRENT_WHEELS]);
	info->distance = take_lidar(info->distance);
	return (info);
}

info_s *init_struct(void)
{
	info_s *info = malloc(sizeof(info_s));

	info->distance = malloc(sizeof(float) * 33);
	return (info);
}
