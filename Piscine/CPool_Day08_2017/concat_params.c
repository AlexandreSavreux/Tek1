/*
** EPITECH PROJECT, 2017
** concat_params.c
** File description:
** Put given arguments into a single string, separated by '\n'
*/

#include <unistd.h>
#include <stdlib.h>

int	my_strlen(char const *);

char *my_strcat_pimped(char *dest, char const *src)
{
	int i;

	for (i = 0; dest[i] != '\0'; i++) {
	}
	for (int n = 0; src[n] != '\0'; n++) {
		dest[i] = src[n];
		i++;
	}
	dest[i] = '\n';
	dest[i + 1] = '\0';
	return (dest);
}

char *concat_params(int argc, char **argv)
{
	char *dest;
	int i = 0;
	int a;

	for (a = 0; argv[a] != '\0' ; a++)
		size = size + strlen(argv[a])
       	//dest = malloc(sizeof(char) * (my_strlen(argv[a]) + argc + 1));
  	for (int n = 0;n < argc; n++) {
		if (my_strlen(argv[n]) > 0)
			dest = my_strcat_pimped(dest, argv[n]);
		}
	return (dest);
}

int main(int argc, char **argv)
{
	concat_params(argc, argv);
	return (0);
}
