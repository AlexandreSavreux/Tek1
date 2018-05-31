/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include <wait.h>
#include "n4s.h"

int my_strlen(char const *str)
{
	int i = 0;

	while (str[i] != '\0') {
		i++;
	}
	return (i);
}

int my_strstr(char *s1, char *s2)
{
	int i = 0;

	if (s1 == NULL || s2 == NULL)
		return (50);
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

int detect_end(char *str)
{
	int i = my_strlen(str) - 1;
	int j = 0;
	char *new;

	if ((new = malloc(sizeof(char) * my_strlen(str))) == NULL)
		return (-1);
	while (str[i] != ':' && str[i] != 0)
		i -= 1;
	i -= 1;
	while (str[i] != ':' && str[i] != 0)
		i -= 1;
	i += 1;
	while (str[i] != ':' && str[i] != 0)
		new[j++] = str[i++];
	new[j] = 0;
	if (my_strstr("Track Cleared", new) == 0) {
		send_command(com_command[FORWARD], 0);
		send_command(com_command[STOP], 0);
		sleep(5);
		return (1);
	}
	free(new);
	return (0);
}

void turn(info_s *info, int way)
{
	send_command(com_command[FORWARD], 0.2);
	send_command(com_command[WHEELS_DIR], (0.4 * way));
	if (way < 0)
		while (info->distance[31] >= info->distance[0])
			info->distance = take_lidar(info->distance);
	else
		while (info->distance[31] <= info->distance[0])
			info->distance = take_lidar(info->distance);
	send_command(com_command[WHEELS_DIR], (0));
	send_command(com_command[FORWARD], 0.5);
}

int main(void)
{
	info_s *info = init_struct();
	char *answer = NULL;
	char *buffer = NULL;

	answer = send_command(com_command[START], 0);
	free(answer);
	answer = send_command(com_command[FORWARD], 0.5);
	free(answer);
	while (1) {
		info->distance = take_lidar(info->distance);
		if (info->distance[10] < 600) {
			turn(info, -1);
		} else if (info->distance[21] < 600)
			turn(info, 1);
		if (info->distance[16] <= 70) {
			answer = send_command(com_command[FORWARD], 0);
			sleep(8);
		}
		answer = send_command(com_command[INFO_LIDAR], 0);
		buffer = get_next_line(0);
		if (detect_end(buffer))
			break;
	}
	free_struct(info);
	return (0);
}
