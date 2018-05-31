/*
** EPITECH PROJECT, 2022
** CPE_getnextline_2017
** File description:
** Created by tiflo,
*/
#include  <criterion/criterion.h>
#include  <criterion/redirect.h>
#include  <fcntl.h>
#include  <unistd.h>

char *get_next_line(int fd);

void open_file(void)
{
	fd = open("data.txt", O_RDONLY);
	cr_redirect_stdout();
}

void close_file(void)
{
	if (fd != -1)
		close(fd);
}

Test(get_next_line, read_line, .init = open_file, .fini = close_file)
{
	char *expected = "Confidence  is so  overrated.kkk";
	char *got = get_next_line(fd);
	cr_assert_str_eq(got, expected);
}
