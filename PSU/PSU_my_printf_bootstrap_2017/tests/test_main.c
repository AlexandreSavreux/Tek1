/*
** EPITECH PROJECT, 2017
** test_main.c
** File description:
** A main test file
*/
#include <criterion/criterion.h>
int sum_stdarg(int i, int nb, ...);
void disp_stdarg(char *s, ...);

Test(sum_stdarg, return_correct_chen_i_is_zero)
{
	int ret = sum_stdarg(0, 3, 21, 25, -4);
	cr_assert_eq(ret, 42);
}

Test(sum_stdarg, return_correct_chen_i_is_one)
{
	int ret = sum_stdarg(1, 5, "Hello", "a", "toto", "", "plop");
	cr_assert_eq(ret, 14);
}

Test(disp_stdarg, test1)
{
	int ret = disp_stdarg("csiis", 'a', "bruh", 34, 49, "plop");
	cr_assert_eq(ret, "z");
}
