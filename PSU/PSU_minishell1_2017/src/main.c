/*
** EPITECH PROJECT, 2022
** My_bool.h
** File description:
** Created by tiflo,
*/
#include <memory.h>
#include "my.h"

static int check_no_args(int ac, char **av)
{
	if (ac != 1 || av[1] != NULL)
		return (1);
	return (0);
}

void ctrl_c_handler(int debug)
{
	(void)debug;
	if (isatty(0))
		my_putstr("\ntiflo$> ");
}

static void init_struct(shell_t *shell, char **env)
{
	shell->env = my_array_dup(env);
	shell->buffer = NULL;
	shell->status = 0;
	shell->path = NULL;
	shell->cmds = NULL;
	shell->arguments = NULL;
	shell->pid = 0;
	shell->home = NULL;
	shell->cmd = NULL;
	shell->ret = 0;
}

int main(int ac, char **av, char **env)
{
	shell_t shell;

	if (check_no_args(ac, av))
		return (84);
	if (isatty(0))
		my_putstr("tiflo$> ");
	init_struct(&shell, env);
	signal(SIGINT, ctrl_c_handler);
	if (my_shell(&shell))
		return (84);
	return (shell.ret);
}