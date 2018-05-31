/*
** EPITECH PROJECT, 2018
** print_tunnel.c
** File description:
** print the tunnels
*/

int check_str(char *str)
{
	int n = 0;

	while (str[n] != '\0') {
		if (str[n] == '-')
			return (1);
		n++;
	}
	return (0);
}
