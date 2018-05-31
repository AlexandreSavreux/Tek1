/*
** EPITECH PROJECT, 2022
** PSU_minishell1
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_pid(shell_t *shell)
{
	shell->pid = fork();
	if (shell->pid == 0) {
		my_execve(shell);
		exit(0);
	} else if (shell->pid > 0) {
		wait(&shell->status);
		if (WIFSIGNALED(shell->status))
			shell->ret = my_signals(shell->status);
	}
}

static void check_if_path(shell_t *shell)
{
	if (check_path(shell) == 0) {
		my_pid(shell);
	} else {
		(cmd_exist(shell)) ? my_pid(shell) :
			(my_printf("%s: Command not found.\n",
				shell->arguments[0]), shell->ret = 1);
	}
}

static int check_if_cmd(shell_t *shell)
{
	my_path(shell);
	if (shell->arguments[0] != NULL) {
		if (!check_builtins(shell)) {
			check_if_path(shell);
		}
	}
	return (0);
}

static int check_if_comma(shell_t *shell)
{
	for (int i = 0; shell->cmds[i] != NULL; i++) {
		shell->arguments = my_str_to_wordarray(shell->cmds[i], ' ');
		check_if_cmd(shell);
	}
	return (0);
}

int my_shell(shell_t *shell)
{
	size_t size = 0;

	while (getline(&shell->buffer, &size, stdin) != -1) {
		shell->cmds = my_str_to_wordarray(shell->buffer, ';');
		signal(SIGINT, ctrl_c_handler);
		check_if_comma(shell);
		if (isatty(0))
			my_putstr("tiflo$> ");
	}
	free(shell->buffer);
	(shell->arguments) ? my_array_free(shell->arguments) : 0;
	my_printf("exit\n");
	return (0);
}