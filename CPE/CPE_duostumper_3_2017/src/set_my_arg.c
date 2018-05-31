/*
** EPITECH PROJECT, 2018
** set_my_arg
** File description:
** set_my_arg
*/
/*
#include "my.h"
#include <stdlib.h>
#include <string.h>
char **modif_av(char **tmp, int i, char *str, int len)
{
	char *arg = my_strnlcpy(tmp[i], len);
	int arg_len = my_strlen(arg);

	printf("%d\n",my_strlen(arg));
	free(tmp[i]);
	tmp[i] = my_strdup_reac(str, 10000);
	if (arg_len > 0)
		tmp[i] = strncat(tmp[i], arg, arg_len);
	free(arg);
	return (tmp);
}

char **set_my_arg(int ac, char **av)
{
	int i = 0;
	char **ret = arrdup(av);

	while (av[i] != NULL && my_strncmp(av[i],my_strdup("--delimiter"),
					11) != 0)
		i++;
	if (av[i] != NULL)
		ret = modif_av(ret, i, "-d", 11);
	i = 0;
	while (av[i] != NULL && my_strncmp(av[i], my_strdup("--characters"),
					12) != 0)
		i++;
	if (av[i] != NULL)
		ret = modif_av(ret, i, "-c", 12);
	i = 0;
	while (av[i] != NULL && my_strncmp(av[i], my_strdup("--fields"),
					8) != 0)
		i++;
	if (av[i] != NULL)
		ret = modif_av(ret, i, "-f", 8);
	my_show_array(ret);
	return (ret);
}
*/