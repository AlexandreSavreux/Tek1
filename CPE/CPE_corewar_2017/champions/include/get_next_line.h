/*
** EPITECH PROJECT, 2022
** CPE_getnextline_2017
** File description:
** Created by tiflo,
*/
#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd);

#ifndef  READ_SIZE
	#define  READ_SIZE (1)
#endif  /* !READ_SIZE  */
#endif //GET_NEXT_LINE_H
