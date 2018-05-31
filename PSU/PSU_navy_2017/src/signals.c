/*
** EPITECH PROJECT, 2022
** PSU_navy_2017
** File description:
** Created by tiflo,
*/
#include "my.h"

void my_receiver(int signo, siginfo_t *info,
	void __attribute__((__unused__)) *context
)
{
	static int nb = 0;
	static int pid = 0;

	my_glob = 0;
	if (signo == SIGUSR2 && nb == 0) {
		my_glob = info->si_pid;
		pid = info->si_pid;
		nb = 0;
	}
	if (pid == info->si_pid) {
		if (signo == SIGUSR1)
			nb++;
		else if (signo == SIGUSR2 && nb != 0) {
			my_glob = nb;
			nb = 0;
		}
	}
}

void my_listener(void)
{
	struct sigaction act;

	act.sa_sigaction = &my_receiver;
	act.sa_flags = SA_SIGINFO;
	sigemptyset(&act.sa_mask);
	if (sigaction(SIGUSR1, &act, NULL) == -1)
		my_putstr("ERROR : SIGUSR1\n");
	if (sigaction(SIGUSR2, &act, NULL) == -1)
		my_putstr("ERROR : SIGUSR2\n");
}

int my_sender(int pid, int nb)
{
	if (pid < 0) {
		my_puterror("ERROR : Bad PID\n");
		return (84);
	}
	if (nb == 0) {
		if (kill(pid, SIGUSR1) == -1) {
			my_puterror("ERROR : cannot send SIGUSR1\n");
			return (84);
		}
	}
	if (nb == 1) {
		if (kill(pid, SIGUSR2) == -1) {
			my_puterror("ERROR : cannot send SIGUSR2\n");
			return (84);
		}
	}
	return (0);
}