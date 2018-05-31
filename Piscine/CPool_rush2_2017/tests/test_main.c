/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>

const char *str = "Hello world";
const int len = 11;

Test(utils, test_my_rush)
{
	cr_assert_eq(alpha_len("Je suis une licorne"), 6);
}
Test(utils, test_my_counter)
{
	cr_assert_eq(counter("Je suis magique", "a"), 1);
}

