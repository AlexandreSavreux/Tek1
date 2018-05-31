/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>

Test(utils, test)
{
	cr_assert_eq(calc(1, 1, '+'), 2);
}
