/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <math.h>

void redirect_all_std(void)
{
	cr_redirect_stdout();
	cr_redirect_stderr();
}

Test(redirect, test_outputs, .init = redirect_all_std)
{
	cr_assert_stderr_eq_str("Invalid number of arguments\n");
}
