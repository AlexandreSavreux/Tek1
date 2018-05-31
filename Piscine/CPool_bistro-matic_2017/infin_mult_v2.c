/*
** EPITECH PROJECT, 2017
** inf multiplication
** File description:
** make inf mult
*/
#include "include/my.h"
#include <stdlib.h>

char *negative(char *result, char *str1, char *str2)
{
	char *les = malloc(sizeof(char) * 2);

	les[0] = '-';
	if (str1[0] == '-' && str2[0] == '-') {
		return (result);
	} else if (str1[0] == '-' || str2[0] == '-') {
		return (my_strcat(les, result));
	} else
		return (result);
}

char *mult(char *nb1, char *nb2, int power)
{
	int i = my_strlen(nb1) - 1;
	int n1;
	int n2 = char_to_int(nb2);
	char *result = malloc(sizeof(char) * (i + 2));
	int power_ten = my_compute_power_rec(10, power);

	for (i; i > 0; i--) {
		n1 = char_to_int(nb1[i]);
		result[i] = int_to_char(n1 * n2 * power_ten);
	}
	my_putstr(result);
}

char *summands_all(char *addition)
{
	int i = 0;
	char *les = malloc(sizeof(char) * 2);

	les[0] = '-';
	for (i = 0; addition[i] == '+' || addition[i] == '\0'; i++);
	if (addition[i] == '\0')
		return (addition);
	return (eval_expr(addition));
}

char *infin_mult(char *str1, char *str2)
{
	int i = my_strlen(str1) > my_strlen(str2) ? my_strlen(str1) :
		my_strlen(str2);
	char *addition = malloc(
		sizeof(char) * (my_strlen(str1) + my_strlen(str2)));
	char *plus = malloc(sizeof(char) * 2);
	int power = 0;

	if (str1[0] == '-')
		str1[0] == '0';
	if (str2[0] == '-')
		str2[0] == '0';
	plus[0] = '+';
	addition = mult(str1[i], str2[i], power);
	for (i = i - 1; i >= 0; i--) {
		power++;
		my_putchar('a');
		addition = my_strcat(addition, plus);
		addition = my_strcat(addition, mult(str1, str2[i], power));
	}
	return (negative(summands_all(addition), str1, str2));
}
