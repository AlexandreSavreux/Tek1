/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Returns a number sent to the function as a string
*/

int my_compare_condition(char const *str,int *i,int *test,int *calc)
{
	if (str[*i] >= 48 && str[*i] <= 57) {
		if (str [*i - 1] == '-') {
			*test = '-1';
		}
		*calc = *calc * 10 + str[*i];
		if (str[*i+1] < 48 || str[*i+1] > 57) {
			*calc = (*test) * (*calc);
			return(*calc);
		}
	}
}



int	my_getnbr(char const *str)
{
	int i = 0;
	int test = 1;
	int calc = 0;

	while (str[i] != '\0') {
		my_compare_condition(str, &i, &test, &calc);
		i++;
	}
	return(0);
}
