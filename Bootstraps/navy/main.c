/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main of my_cook
*/
#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sig_handler(int signo)
{
	if (signo == SIGUSR1)
		printf("received SIGUSR1\n");
	else if (signo == SIGKILL)
		printf("received SIGKILL\n");
	else if (signo == SIGSTOP)
		printf("received SIGSTOP\n");
}

int main(void)
{
	if (signal(SIGUSR1, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGUSR1\n");
	if (signal(SIGKILL, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGKILL\n");
	if (signal(SIGSTOP, sig_handler) == SIG_ERR)
		printf("\ncan't catch SIGSTOP\n");
	while(1)
		sleep(1);
	return 0;
}