/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>

int match(char const *s1, char const *s2);

const char *str = "Hello";

Test(utils, my_test)
{
	cr_assert_eq(match(str, "z"), 0);
}
Test(utils, my_test2)
{
	cr_assert_eq(match(str, "h*l"), 1);
}
Test(utils, my_test3)
{
	cr_assert_eq(match(str, "***"), 1);
}
Test(utils, my_test5)
{
	cr_assert_eq(match(str, "ol"), 0);
}
Test(utils, my_test6)
{
	cr_assert_eq(match(str, "hello Marvin"), 0);
}

