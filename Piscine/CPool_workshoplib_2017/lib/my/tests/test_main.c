/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>

Test(utils, test)
{
	cr_assert_eq(my_compute_square_root(1), 1);
}
Test(utils, test2)
{
	cr_assert_eq(my_compute_square_root(0), 0);
}

