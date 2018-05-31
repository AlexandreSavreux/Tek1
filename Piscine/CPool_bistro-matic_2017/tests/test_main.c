/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>

Test(utils, test)
{
	cr_assert_eq(add("1", "1"), "2");
}

Test(utils, test2)
{
	cr_assert_eq(add("11", "1"), "12");
}
Test(utils, test3)
{
	cr_assert_eq(add("11", "11"), "2");
}
Test(utils, test4)
{
	cr_assert_eq(add("11", "11"), "0");
}
