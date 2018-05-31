#include <criterion/criterion.h>

const char *str = "Hello world";
const int len = 11;

Test(utils, is_str_length_equal_to_len_v1)
{
	cr_assert(strlen(str) == len);
}
Test(utils, is_str_length_equal_to_len_v2)
{
	cr_assert_eq(strlen(str), len);
}
Test(utils, is_str_length_equal_to_len_v3)
{
	cr_assert_not(strlen(str) != len);
}
