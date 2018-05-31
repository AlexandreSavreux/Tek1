#include <stdio.h>
#include <memory.h>
#include "my.h"

typedef struct oui {
	int i;
	char c;
	char str[40];
} oui_t;

int main()
{
	int fd = open("./one-structure.yolo", O_CREAT | O_WRONLY, 0640);
	oui_t test;

	test.i = 92837;
	strcpy(test.str, "Corewar is swag!!");
	test.c = 'k';

	if (fd != 0) {
		write(fd, &test.i, sizeof(int));
		write(fd, &test.c, sizeof(char));
		write(fd, test.str, strlen(test.str));
		close(fd);
	}
	return 0;
}