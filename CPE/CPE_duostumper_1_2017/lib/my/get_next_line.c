/*
** EPITECH PROJECT, 2018
** get_next_line
** File description:
** get_next_line
*/

#include "my.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

void check_finish_str(char *str, int fd)
{
	static int check_finish = READ_SIZE;

	check_finish = read(fd, str, READ_SIZE);
	if (check_finish != READ_SIZE)
		str[check_finish] = '\0';
}


char get_next_char(char *str, int fd)
{
	static int i = 0;
	static int check_finish = READ_SIZE;
	char c;

	if (str == NULL)
		return ('\n');
	c = str[i];
	if (c == '\n') {
		c = '\0';
		if (fd == 0 && c == '\0')
			i = -1;
	}
	i++;
	if (i == READ_SIZE) {
		i = 0;
		check_finish_str(str, fd);
		if (str == NULL)
			return ('\n');
	}
	return (c);
}

char *verify(char buff[], int fd)
{
	if (buff == NULL || buff[0] == '\0')
		read(fd, buff, READ_SIZE);
	else if (my_strlen(buff) != READ_SIZE)
		return (NULL);
	return (buff);
}

char *get_next_line(int fd)
{
	char *ret = new_str(READ_SIZE);
	int i = 0;
	static char buff[READ_SIZE];
	char c = 'a';

	if (verify(buff, fd) == NULL)
		return (NULL);
	while (c != '\0') {
		c = get_next_char(buff, fd);
		if (c == '\n')
			return (NULL);
		else if (i++ % (READ_SIZE) == 0)
			ret = my_strdup_reac(ret, READ_SIZE);
		ret[i - 1] = c;
		ret[i] = '\0';
	}
	buff[0] = (fd == 0) ? '\0' : buff[0];
	if (ret[0] == '\0')
		return (NULL);
	return (ret);
}
