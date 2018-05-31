/*
** EPITECH PROJECT, 2022
** CPE_n4s_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include "my.h"
#include <stdio.h>
#include "n4s.h"

char *send_command(command_t command, float value)
{
	char *buf = NULL;
	size_t to_read = 0;

	if (command.type == FLOAT) {
		dprintf(1, "%s%.2f", command.command, value);
	} else if (command.type == INT)
		dprintf(1, "%s%d", command.command, (int)value);
	else
		dprintf(1, "%s", command.command);
	write(1, "\n", 1);
	getline(&buf, &to_read, stdin);
	return (buf);
}