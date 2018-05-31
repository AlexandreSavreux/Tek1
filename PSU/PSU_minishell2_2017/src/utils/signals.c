/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by Florian Louvet,
*/
#include "my.h"

int my_signals(int signal)
{
	int i = 0;
	(WTERMSIG(signal) == SIGSEGV) ?
		my_printf("Segmentation fault (core dumped)\n", i = 1) : 0;
	(WTERMSIG(signal) == SIGHUP) ? my_printf("hangup\n", i = 1) : 0;
	(WTERMSIG(signal) == SIGQUIT) ?
		my_printf("Quit (core dumped)\n", i = 1) : 0;
	(WTERMSIG(signal) == SIGILL) ?
		my_printf("Illegal instruction (core dumped)\n", i = 1) : 0;
	(WTERMSIG(signal) == SIGABRT) ?
		my_printf("Aborted (core dumped)\n", i = 1) : 0;
	(WTERMSIG(signal) == SIGIOT) ?
		my_printf("Aborted (core dumped)\n", i = 1) : 0;
	(WTERMSIG(signal) == SIGBUS) ? my_printf("Aborted (core dumped)\n") : 0;
	(WTERMSIG(signal) == SIGKILL) ? my_printf("Killed\n") : 0;
	(WTERMSIG(signal) == SIGTERM) ? my_printf("Terminated\n") : 0;
	return (i);
}