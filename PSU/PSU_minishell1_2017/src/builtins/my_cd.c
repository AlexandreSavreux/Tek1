/*
** EPITECH PROJECT, 2022
** PSU_minishell2_2017
** File description:
** Created by tiflo,
*/
#include <sys/stat.h>
#include "my.h"

static int my_access(shell_t *shell)
{
	if (access(shell->arguments[1], F_OK) < 0) {
		my_puterror(shell->arguments[1]);
		my_puterror(": no such file or directory\n");
		return (-1);
	}
	return (0);
}

static int my_check(shell_t *shell)
{
	struct stat infos;

	if (my_access(shell) == -1)
		return -(1);
	if (stat(shell->arguments[1], &infos) < 0) {
		my_puterror(shell->arguments[1]);
		my_puterror(": not found\n");
		return (-1);
	}
	if (!S_ISDIR(infos.st_mode)) {
		my_puterror(shell->arguments[1]);
		my_puterror(": is not a directory.\n");
		return (-1);
	}
	if (access(shell->arguments[1], X_OK) < 0) {
		my_puterror(shell->arguments[1]);
		my_puterror(": permission denied.\n");
		return (-1);
	}
	return (0);
}

static void change_pwd(shell_t *shell)
{
	char *temp = NULL;

	temp = getcwd(temp, 0);
	(recup_from_env("PWD=", shell->env)) ? run_my_setenv(shell, "OLDPWD",
		recup_from_env("PWD=", shell->env)) : 0;
	(recup_from_env("OLDPWD=", shell->env)) ?
		run_my_setenv(shell, "PWD", temp) : 0;
}

static int my_second_cd(shell_t *shell)
{
	if (chdir(shell->arguments[1]) < 0) {
		my_puterror(shell->arguments[1]);
		my_puterror(": can not open directory.\n");
		return (1);
	}
	return (0);
}

int my_cd(shell_t *shell)
{
	if ((my_strstr("cd", shell->arguments[0])) == 0) {
		my_home(shell);
		if (shell->arguments[1] == NULL) {
			(shell->home != NULL) ? chdir(shell->home) : 0;
			change_pwd(shell);
			return (0);
		}
		if (my_strstr("-", shell->arguments[1]) == 0) {
			(recup_from_env("OLDPWD=", shell->env)) ?
				chdir(recup_from_env("OLDPWD=", shell->env)) :
				0;
			change_pwd(shell);
			return (0);
		}
		if (my_check(shell) == -1 || my_second_cd(shell) == 1)
			return (0);
		change_pwd(shell);
		return (0);
	}
	return (1);
}
