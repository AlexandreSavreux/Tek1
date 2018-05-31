/*
** EPITECH PROJECT, 2022
** CPE_getnextline_2017
** File description:
** Created by tiflo,
*/
#include "get_next_line.h"

static char *my_strdup(const char *src)
{
	int i = 0;
	char *dest;

	while (src && src[i])
		i++;
	if (!(dest = malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i] != '\0') {
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static char *my_pimped_strncpy(char *dest, char const *src, int n, int bill)
{
	int i = 0;
	int j = 0;

	if (bill == 1) {
		for (i = 0; dest != NULL && dest[i]; i++);
		while (src[j] && j < n) {
			dest[i] = src[j];
			i++;
			j++;
		}
		dest[i] = '\0';
		return (dest);
	}
	for (; src[i] && i < n; i++)
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

static char *my_realloc(char *str, size_t len)
{
	char *dest;
	int str_len = 0;

	for (; str && str[str_len]; str_len++);
	if (!str) {
		if (!(dest = malloc(sizeof(char) * len)))
			return (NULL);
		if (len > 0)
			dest[0] = '\0';
		return (dest);
	}
	if (!(dest = malloc(sizeof(char) * (str_len + 1 + len))))
		return (NULL);
	dest = my_pimped_strncpy(dest, str, str_len, 0);
	free(str);
	return (dest);
}

static char *my_buffer(char *buf, char *buf_full, const int fd, int end)
{
	int tmp = 0;

	while (42) {
		end = 0;
		while (buf_full && buf_full[tmp])
			(buf_full[tmp++] == '\n') ? end++ : 0;
		if (end != 0)
			return (buf_full);
		if ((tmp = read(fd, buf, READ_SIZE)) <= 0 ||
			(buf[tmp] = '\0') ||
			!(buf_full = my_realloc(buf_full, READ_SIZE + 1))) {
			if (buf_full != NULL && buf_full[0] != '\0')
				return (buf_full);
			free(buf);
			free(buf_full);
			return (NULL);
		}
		buf_full = my_pimped_strncpy(buf_full, buf, READ_SIZE, 1);
	}
}

char *get_next_line(int fd)
{
	static char *buffer;
	char *buff;
	char *line;
	int j = 0;
	int i = 0;

	if (READ_SIZE <= 0 ||
		!(buff = malloc(sizeof(char) * (READ_SIZE + 1))) ||
		!(buffer = my_buffer(buff, buffer, fd, 0)))
		return (NULL);
	for (; buffer[j + i] && buffer[j + i] != '\n'; i++);
	free(buff);
	buff = buffer;
	if (!(line = my_realloc((line = NULL), i + 2)) || !(buffer =
		buff[j + i] == '\0' ? my_strdup("\0") :
			my_strdup(buff + j + i + 1)))
		return (NULL);
	line = my_pimped_strncpy(line, buff + j, i + 1, 0);
	line[i] = '\0';
	free(buff);
	return (line);
}
