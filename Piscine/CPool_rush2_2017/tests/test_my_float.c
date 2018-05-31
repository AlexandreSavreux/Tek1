/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>

const char *str = "Hello world";
const int len = 11;

Test(utils, returns_a_float)
{
	cr_assert(my_float(6625), 66.25);
}
Test(utils, returns_a_floatV2)
{
	cr_assert_eq(98775, 98.775);
}
Test(utils, is_str_length_equal_to_len_v3)
{
	cr_assert_not(my_float(0), 0);
}

