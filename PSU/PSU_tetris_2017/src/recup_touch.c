/*
** EPITECH PROJECT, 2018
** recu_touch.c
** File description:
** take the touch from the term
*/

#include <term.h>
#include "tetris.h"

int recup_touch(char *term, tetris_t *tetris)
{
	int ret;

	setupterm(term, 1, &ret);
	tetris->touch[1] = tigetstr("kcub1");
	tetris->touch[2] = tigetstr("kcuf1");
	tetris->touch[3] = tigetstr("kcuu1");
	tetris->touch[4] = tigetstr("kcud1");
	return (0);
}
